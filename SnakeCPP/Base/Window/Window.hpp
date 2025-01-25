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
 * Window.hpp
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <windows.h>
#include <string>

class Window
{
private:
    HWND m_hwnd;
    std::string m_title;

public:
    Window(const std::string &title);

    bool create(const HINSTANCE &hInstance);
    void show(const int &nCmdShow);
    int run();

private:
    LRESULT handleMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif