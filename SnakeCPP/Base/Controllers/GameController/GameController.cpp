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
 * GameController.cpp
 */

#include "GameController.hpp"
#include "../Renderer/Common/Renderer.hpp"
#include "../../Constants/Constants.hpp"

GameController::GameController()
{
    int cellWidth = WINDOW_WIDTH / COLS;
    int cellHeight = WINDOW_HEIGHT / ROWS;

    // Initialize snake in the center.
    int startX = (COLS / 2) * cellWidth;
    int startY = (ROWS / 2) * cellHeight;
    m_snake = std::make_unique<Snake>(startX, startY, cellWidth, cellHeight);

    // Initialize fruit.
    m_fruit = std::make_unique<Fruit>(cellWidth, cellHeight);
    m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
}

void GameController::handleInput(const WPARAM &keyCode)
{
    if (m_snake)
        m_snake->handleInput(keyCode);
}

bool GameController::update()
{
    if (!m_snake || !m_fruit)
        return false;

    // Move snake and check collisions
    m_snake->update(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (m_snake->getHead() == m_fruit->getPosition())
    {
        m_snake->grow();
        m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
    }

    return !m_snake->collideWithSelf(); // Return false if game over.
}

void GameController::render(Renderer &renderer)
{
    if (m_fruit)
        m_fruit->draw(renderer, FRUIT_COLOR);

    if (m_snake)
        m_snake->draw(renderer, SNAKE_COLOR);
}