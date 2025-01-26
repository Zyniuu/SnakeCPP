/**
 * Snake game written in C++ using winAPI.
 * Copyright (C) 2025  Mateusz Zynek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Window.cpp
 */

#include "Window.hpp"
#include "../Constants/Constants.hpp"
#include <chrono>

Window::Window(const std::string &title)
    : m_title(title), m_isRunning(false), m_isInputPending(false) {}

Window::~Window()
{
    m_isRunning = false;

    // Wait for the update thread to finish execution if it is still running.
    if (m_updateThread.joinable())
        m_updateThread.join();

    // Clean up the memory bitmap if it was created.
    if (m_memoryBitmap)
    {
        DeleteObject(m_memoryBitmap);
        m_memoryBitmap = nullptr;
    }

    // Clean up the memory device context if it was created.
    if (m_memoryDC)
    {
        DeleteObject(m_memoryDC);
        m_memoryDC = nullptr;
    }

    // Delete all created brushes.
    for (auto &[color, brush] : m_brushes)
        DeleteObject(brush);
    m_brushes.clear();
}

bool Window::create(const HINSTANCE &hInstance)
{
    // Define the window class structure
    WNDCLASS wc = {};
    wc.lpfnWndProc = windowProc;                 // Set the window procedure
    wc.hInstance = hInstance;                    // Set the instance handle
    wc.lpszClassName = m_title.c_str();          // Set the class name
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW); // Set default cursor inside the window to an arrow

    // Register the window class
    if (!RegisterClass(&wc))
    {
        MessageBox(nullptr, "Failed to register window class.", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    // Define the window style and dimensions.
    DWORD windowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX;
    RECT windowRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    // Adjust the window size to match with the applied styles
    AdjustWindowRect(&windowRect, windowStyle, FALSE);

    // Adjusted width and height
    int windowWidth = windowRect.right - windowRect.left;
    int windowHeight = windowRect.bottom - windowRect.top;
    // Centering the window on the screen
    int windowPosX = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
    int windowPosY = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

    // Create the window
    m_hwnd = CreateWindowEx(
        0,                         // Optional window styles
        m_title.c_str(),           // Window class name
        m_title.c_str(),           // Window title
        windowStyle,               // Window style
        windowPosX, windowPosY,    // Position
        windowWidth, windowHeight, // Size
        nullptr,                   // Parent window
        nullptr,                   // Menu
        hInstance,                 // Instance handle
        this                       // Pass the Window instance as additional application data for later retrieval.
    );

    if (!m_hwnd)
    {
        MessageBox(nullptr, "Failed to create a window.", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    // Initialize double buffering for smooth rendering.
    HDC hdc = GetDC(m_hwnd);
    m_memoryDC = CreateCompatibleDC(hdc);                                      // Create a compatible memory device context.
    m_memoryBitmap = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT); // Create a bitmap for double buffering.
    SelectObject(m_memoryDC, m_memoryBitmap);                                  // Select the bitmap into the memory DC.
    ReleaseDC(m_hwnd, hdc);                                                    // Release the device context.

    return true;
}

void Window::show(const int &nCmdShow) { ShowWindow(m_hwnd, nCmdShow); }

void Window::run()
{
    m_isRunning = true;
    m_updateThread = std::thread(&Window::update, this); // Start the update loop in a separate thread.
    MSG msg = {};

    while (GetMessage(&msg, nullptr, 0, 0) && m_isRunning)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void Window::update()
{
    double refreshTime = 1000 / FPS; // Target refresh time per frame (in milliseconds).

    // Calculate cell dimensions and initialize snake and fruit objects.
    int width = WINDOW_WIDTH / COLS;
    int height = WINDOW_HEIGHT / ROWS;
    int x = (COLS / 2) * width;
    int y = (ROWS / 2) * height;

    m_snake = std::make_unique<Snake>(x, y, width, height);
    m_fruit = std::make_unique<Fruit>(width, height);

    m_fruit->regenerate(COLS, ROWS, m_snake->getBody());

    while (m_isRunning)
    {
        auto startTime = std::chrono::high_resolution_clock::now();

        if (m_snake && m_fruit)
        {
            // Handle input if pending.
            if (m_isInputPending)
            {
                m_snake->handleInput(m_lastKey);
                m_isInputPending = false;
            }

            // Update the snake's position and check collisions.
            m_snake->update(WINDOW_WIDTH, WINDOW_HEIGHT);

            if (m_snake->getHead() == m_fruit->getPosition())
            {
                m_snake->grow();
                m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
            }

            // End the game if the snake collides with itself.
            if (m_snake->collideWithSelf())
                m_isRunning = false;
        }

        InvalidateRect(m_hwnd, nullptr, FALSE); // Request a window redraw.

        // Maintain the target refresh time by calculating elapsed time.
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = endTime - startTime;

        if (elapsed.count() < refreshTime)
        {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(
                    static_cast<int>(refreshTime - elapsed.count())
                )
            );
        }
    }
}

HBRUSH Window::getBrush(const COLORREF &color)
{
    auto it = m_brushes.find(color);

    if (it != m_brushes.end())
        return it->second;

    HBRUSH brush = CreateSolidBrush(color);
    m_brushes[color] = brush;
    return brush;
}

LRESULT CALLBACK Window::windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window *window = nullptr;

    if (uMsg == WM_NCCREATE)
    {
        CREATESTRUCT *createStruct = reinterpret_cast<CREATESTRUCT *>(lParam);
        window = reinterpret_cast<Window *>(createStruct->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window)); // Store the window pointer.

        window->m_hwnd = hwnd;
    }
    else
        window = reinterpret_cast<Window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window)
        return window->handleMsg(uMsg, wParam, lParam); // Forward the message to the window instance.

    return DefWindowProc(hwnd, uMsg, wParam, lParam); // Default message processing.
}

LRESULT Window::handleMsg(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(m_hwnd, &ps);

        // Clear the window with the background color.
        RECT clientRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        FillRect(m_memoryDC, &clientRect, getBrush(BACKGROUND_COLOR));

        // Draw the fruit and the snake.
        if (m_fruit)
            m_fruit->draw(m_memoryDC, getBrush(FRUIT_COLOR));

        if (m_snake)
            m_snake->draw(m_memoryDC, getBrush(SNAKE_COLOR));

        // Copy the off-screen buffer to the actual window.
        BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, m_memoryDC, 0, 0, SRCCOPY);

        EndPaint(m_hwnd, &ps);
        return 0;
    }

    case WM_KEYDOWN:
    {
        if (!m_isInputPending)
        {
            m_lastKey = wParam; // Record the last pressed key.
            m_isInputPending = true;
        }
        return 0;
    }

    case WM_DESTROY:
    {
        PostQuitMessage(0); // Signal the application to exit.
        return 0;
    }

    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
}