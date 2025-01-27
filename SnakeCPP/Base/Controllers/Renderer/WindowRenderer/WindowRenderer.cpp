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
 * WindowRenderer.cpp
 */

#include "WindowRenderer.hpp"
#include "../../../Constants/Constants.hpp"

WindowRenderer::WindowRenderer(const HDC &hdc) : m_hdc(hdc) {}

WindowRenderer::~WindowRenderer()
{
    // Delete device context.
    if (m_hdc)
    {
        DeleteObject(m_hdc);
        m_hdc = nullptr;
    }

    // Delete all created brushes.
    for (auto &[color, brush] : m_brushes)
        DeleteObject(brush);
    m_brushes.clear();
}

void WindowRenderer::clear(const COLORREF &color)
{
    RECT rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}; // Rectangle representing the window.
    FillRect(m_hdc, &rect, getBrush(color));         // Fill the whole window using the brush.
}

void WindowRenderer::drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color)
{
    RECT rect = {x, y, x + width, y + height}; // Rectangle with the specified size and position.
    FillRect(m_hdc, &rect, getBrush(color));   // Fill the specified rectangle using the brush.
}

HBRUSH WindowRenderer::getBrush(const COLORREF &color)
{
    auto it = m_brushes.find(color); // Look for the brush.

    if (it != m_brushes.end())
        return it->second; // Return if exists.

    HBRUSH brush = CreateSolidBrush(color); // If not, create a new one.
    m_brushes[color] = brush;               // Add it to the collection.
    return brush;
}