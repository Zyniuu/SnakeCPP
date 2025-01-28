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

constexpr int WINDOW_WIDTH = 450;  ///< The width of the game window in pixels.
constexpr int WINDOW_HEIGHT = 705; ///< The height of the game window in pixels.
constexpr int ROWS = 47;           ///< The number of rows in the game grid.
constexpr int COLS = 30;           ///< The number of columns in the game grid.
constexpr int FPS = 30;            ///< The frame rate of the game in frames per second.

constexpr COLORREF BACKGROUND_COLOR = RGB(44, 62, 80); ///< The background color of the game window.
constexpr COLORREF SNAKE_COLOR = RGB(236, 240, 241);   ///< The color of the snake.
constexpr COLORREF FRUIT_COLOR = RGB(192, 57, 43);     ///< The color of the fruit.

#endif