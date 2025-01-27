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
 * GameController.hpp
 */

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "../../../GameObjects/Snake/Snake.hpp"
#include "../../../GameObjects/Fruit/Fruit.hpp"
#include <memory>

/**
 * @class GameController
 * @brief Manages the logic of the game, including the snake, fruit, and collisions.
 */
class GameController
{
private:
    std::unique_ptr<Snake> m_snake; // The Snake object.
    std::unique_ptr<Fruit> m_fruit; // The fruit object.

public:
    /**
     * @brief Initializes the game (creates snake and fruit).
     */
    GameController();

    /**
     * @brief Handles player input.
     *
     * @param keyCode The virtual key code of the pressed key.
     */
    void handleInput(WPARAM keyCode);

    /**
     * @brief Updates the game state (moves snake, checks collisions).
     *
     * @return True if the game should continue, false if it's game over.
     */
    bool update();

    /**
     * @brief Renders the game objects using the provided renderer.
     *
     * @param renderer Renderer used to draw on the window.
     */
    void render(class Renderer &renderer);
};

#endif