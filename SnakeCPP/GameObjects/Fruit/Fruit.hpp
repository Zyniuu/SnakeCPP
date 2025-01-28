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
 * Fruit.hpp
 */

#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "../Common/GameObject.hpp"

/**
 * @class Fruit
 * @brief Represents the fruit in the game.
 */
class Fruit : public GameObject
{
private:
    int m_x, m_y; ///< The position of the fruit.

public:
    /**
     * @brief Constructs a Fruit object.
     *
     * @param width The width of the fruit.
     * @param height The height of the fruit.
     */
    Fruit(const int &width, const int &height);

    /**
     * @brief Gets the position of the fruit.
     *
     * @return A pair representing the x and y coordinates of the fruit.
     */
    std::pair<int, int> getPosition() const;

    /**
     * @brief Regenerates the fruit at a new position not occupied by the snake.
     *
     * @param cols The number of columns in the game grid.
     * @param rows The number of rows in the game grid.
     * @param snakeBody The current body of the snake.
     */
    void regenerate(const int &cols, const int &rows, const std::deque<std::pair<int, int>> &snakeBody);

    /**
     * @brief Draws the fruit on the screen.
     *
     * @param renderer Renderer used to draw on the window.
     * @param color Color of the fruit.
     */
    void draw(class Renderer &renderer, const COLORREF &color) override;
};

#endif