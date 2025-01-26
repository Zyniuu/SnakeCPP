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

    if (m_updateThread.joinable())
        m_updateThread.join();

    if (m_memoryBitmap)
    {
        DeleteObject(m_memoryBitmap);
        m_memoryBitmap = nullptr;
    }

    if (m_memoryDC)
    {
        DeleteObject(m_memoryDC);
        m_memoryDC = nullptr;
    }

    for (auto &[color, brush] : m_brushes)
        DeleteObject(brush);
    m_brushes.clear();
}

bool Window::create(const HINSTANCE &hInstance)
{
    WNDCLASS wc = {};
    wc.lpfnWndProc = windowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = m_title.c_str();
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

    if (!RegisterClass(&wc))
    {
        MessageBox(nullptr, "Failed to register window class.", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    DWORD windowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX;
    RECT windowRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    AdjustWindowRect(&windowRect, windowStyle, FALSE);

    int windowWidth = windowRect.right - windowRect.left;
    int windowHeight = windowRect.bottom - windowRect.top;
    int windowPosX = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
    int windowPosY = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

    m_hwnd = CreateWindowEx(
        0,
        m_title.c_str(),
        m_title.c_str(),
        windowStyle,
        windowPosX, windowPosY,
        windowWidth, windowHeight,
        nullptr,
        nullptr,
        hInstance,
        this
    );

    if (!m_hwnd)
    {
        MessageBox(nullptr, "Failed to create a window.", "Error", MB_OK | MB_ICONERROR);
        return false;
    }

    HDC hdc = GetDC(m_hwnd);
    m_memoryDC = CreateCompatibleDC(hdc);
    m_memoryBitmap = CreateCompatibleBitmap(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(m_memoryDC, m_memoryBitmap);
    ReleaseDC(m_hwnd, hdc);

    return true;
}

void Window::show(const int &nCmdShow) { ShowWindow(m_hwnd, nCmdShow); }

void Window::run()
{
    m_isRunning = true;
    m_updateThread = std::thread(&Window::update, this);
    MSG msg = {};

    while (GetMessage(&msg, nullptr, 0, 0) && m_isRunning)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void Window::update()
{
    double refreshTime = 1000 / FPS;

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
            if (m_isInputPending)
            {
                m_snake->handleInput(m_lastKey);
                m_isInputPending = false;
            }

            m_snake->update(WINDOW_WIDTH, WINDOW_HEIGHT);

            if (m_snake->getHead() == m_fruit->getPosition())
            {
                m_snake->grow();
                m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
            }

            if (m_snake->collideWithSelf())
                m_isRunning = false;
        }

        InvalidateRect(m_hwnd, nullptr, FALSE);

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
        SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));

        window->m_hwnd = hwnd;
    }
    else
        window = reinterpret_cast<Window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window)
        return window->handleMsg(uMsg, wParam, lParam);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

LRESULT Window::handleMsg(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(m_hwnd, &ps);

        RECT clientRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        FillRect(m_memoryDC, &clientRect, getBrush(BACKGROUND_COLOR));

        if (m_fruit)
            m_fruit->draw(m_memoryDC, getBrush(FRUIT_COLOR));

        if (m_snake)
            m_snake->draw(m_memoryDC, getBrush(SNAKE_COLOR));

        BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, m_memoryDC, 0, 0, SRCCOPY);

        EndPaint(m_hwnd, &ps);
        return 0;
    }

    case WM_KEYDOWN:
    {
        if (!m_isInputPending)
        {
            m_lastKey = wParam;
            m_isInputPending = true;
        }
        return 0;
    }

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }

    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
}