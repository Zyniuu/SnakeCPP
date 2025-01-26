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

Window::Window(const std::string &title) : m_title(title) {}

Window::~Window()
{
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

    int windowPosX = (GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH) / 2;
    int windowPosY = (GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT) / 2;

    m_hwnd = CreateWindowEx(
        0,
        m_title.c_str(),
        m_title.c_str(),
        WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
        windowPosX, windowPosY,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        nullptr,
        nullptr,
        hInstance,
        this);

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

int Window::run()
{
    MSG msg = {};

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
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
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }

    default:
        return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
    }
}