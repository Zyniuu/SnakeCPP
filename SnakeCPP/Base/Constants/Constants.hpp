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
 * Constants.hpp
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <windows.h>

constexpr int WINDOW_WIDTH = 450;
constexpr int WINDOW_HEIGHT = 705;
constexpr int ROWS = 47;
constexpr int COLS = 30;
constexpr int FPS = 30;

constexpr COLORREF BACKGROUND_COLOR = RGB(44, 62, 80);
constexpr COLORREF SNAKE_COLOR = RGB(236, 240, 241);
constexpr COLORREF FRUIT_COLOR = RGB(192, 57, 43);

#endif