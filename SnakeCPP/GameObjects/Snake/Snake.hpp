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
 * Snake.hpp
 */

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "../Common/GameObject.hpp"

/**
 * @class Snake
 * @brief Represents the snake in the game.
 */
class Snake : public GameObject
{
private:
    std::deque<std::pair<int, int>> m_body;                      // The body of the snake as a deque of positions.
    std::unordered_set<std::pair<int, int>, pairHash> m_bodySet; // A set for quick collision detection.
    int m_dx, m_dy;                                              // The movement direction of the snake.
    bool m_isGrowing;                                            // Whether the snake is growing.
    bool m_isCollided;                                           // Whether the snake has collided with itself.

public:
    /**
     * @brief Constructs a Snake object.
     *
     * @param x The initial x-coordinate of the snake's head.
     * @param y The initial y-coordinate of the snake's head.
     * @param width The width of each segment of the snake.
     * @param height The height of each segment of the snake.
     */
    Snake(const int &x, const int &y, const int &width, const int &height);

    /**
     * @brief Updates the snake's position and checks for collisions.
     *
     * @param windowWidth The width of the game window.
     * @param windowHeight The height of the game window.
     */
    void update(const int &windowWidth, const int &windowHeight);

    /**
     * @brief Grows the snake by one segment.
     */
    void grow();

    /**
     * @brief Handles user input to change the snake's direction.
     *
     * @param keyCode The virtual key code of the pressed key.
     */
    void handleInput(const WPARAM &keyCode);

    /**
     * @brief Checks if the snake has collided with itself.
     *
     * @return True if the snake has collided, false otherwise.
     */
    bool collideWithSelf() const;

    /**
     * @brief Gets the position of the snake's head.
     *
     * @return A pair representing the x and y coordinates of the head.
     */
    std::pair<int, int> getHead() const;

    /**
     * @brief Gets the body of the snake.
     *
     * @return A deque representing the snake's body segments.
     */
    std::deque<std::pair<int, int>> getBody() const;

    /**
     * @brief Draws the snake on the screen.
     *
     * @param renderer Renderer used to draw on the window.
     * @param color Color of the snake.
     */
    void draw(class Renderer &renderer, const COLORREF &color) override;

private:
    /**
     * @brief Adjusts the position of the snake's head based on boundaries.
     *
     * @param windowWidth The width of the game window.
     * @param windowHeight The height of the game window.
     * @return A pair representing the new position of the head.
     */
    std::pair<int, int> adjustHead(const int &windowWidth, const int &windowHeight);
};

#endif