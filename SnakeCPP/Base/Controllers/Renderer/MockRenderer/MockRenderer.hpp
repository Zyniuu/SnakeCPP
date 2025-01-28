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
 * MockRenderer.hpp
 */

#ifndef MOCKRENDERER_HPP
#define MOCKRENDERER_HPP

#include "../Common/Renderer.hpp"

/**
 * @class MockRenderer
 * @brief Mock class used for testing
 */
class MockRenderer : public Renderer
{
public:
    int drawCalls = 0;
    int clearCalls = 0;

    void clear(const COLORREF &color)
    {
        clearCalls++;
    }

    void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) override
    {
        drawCalls++;
    }
};

#endif