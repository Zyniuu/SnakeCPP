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
 * Renderer.hpp
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <windows.h>

/**
 * @class Renderer
 * @brief Abstracts rendering logic to allow testing.
 */
class Renderer
{
public:
    virtual void clear(const COLORREF &color) = 0;
    virtual void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) = 0;
};

#endif