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
 * WindowRenderer.hpp
 */

#ifndef WINDOWRENDERER_HPP
#define WINDOWRENDERER_HPP

#include "../Common/Renderer.hpp"
#include <unordered_map>

/**
 * @class WindowRenderer
 * @brief Handles the window rendering logic.
 */
class WindowRenderer : public Renderer
{
private:
    HDC m_hdc;                                      ///< Device context to draw on.
    std::unordered_map<COLORREF, HBRUSH> m_brushes; ///< Collection of brushes for different colors.

public:
    /**
     * @brief Constructs the window renderer.
     *
     * @param hdc Device context to draw on.
     */
    WindowRenderer(const HDC &hdc);

    /**
     * @brief Releases recources of the renderer.
     */
    ~WindowRenderer();

    /**
     * @brief Clears the window with a specified background color.
     *
     * @param color Window background color.
     */
    void clear(const COLORREF &color) override;

    /**
     * @brief Draws rectangle on the window with a specified color.
     *
     * @param x X coordinate of the rectangle.
     * @param y Y coordinate of the rectangle.
     * @param width Width of the rectangle.
     * @param height Height of the rectangle.
     * @param color Color of the rectangle
     */
    void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) override;

private:
    /**
     * @brief Retrieves or creates a brush of the specified color.
     *
     * @param color The color of the brush.
     * @return The handle to the brush.
     */
    HBRUSH getBrush(const COLORREF &color);
};

#endif