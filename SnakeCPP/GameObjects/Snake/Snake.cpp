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
 * Snake.cpp
 */

#include "Snake.hpp"
#include "../../Base/Controllers/Renderer/Common/Renderer.hpp"

Snake::Snake(const int &x, const int &y, const int &width, const int &height)
    : GameObject(width, height), m_dx(0), m_dy(height), m_isGrowing(false), m_isCollided(false)
{
    // Add the initial position of the snake's head to its body and position set.
    m_body.push_back({x, y});
    m_bodySet.insert({x, y});
}

void Snake::update(const int &windowWidth, const int &windowHeight)
{
    // Calculate the new head position, considering window boundaries.
    std::pair<int, int> newHead = adjustHead(windowWidth, windowHeight);

    // Check if the new head collides with the body.
    if (m_bodySet.count(newHead) > 0)
        m_isCollided = true;

    // Add the new head position to the front of the snake's body.
    m_body.push_front(newHead);
    m_bodySet.insert(newHead);

    // If the snake is not growing, remove the last segment (tail).
    if (!m_isGrowing)
    {
        std::pair<int, int> tail = m_body.back();
        m_body.pop_back();
        m_bodySet.erase(tail);
    }
    else
        m_isGrowing = false; // Reset the growth flag after adding a segment.
}

void Snake::grow() { m_isGrowing = true; }

void Snake::handleInput(WPARAM keyCode)
{
    switch (keyCode)
    {
    case VK_UP: // Up arrow key.
    {
        if (m_dy != m_height) // Change to vertical movement if the snake is currently moving horizontally.
        {
            m_dy = -m_height;
            m_dx = 0;
        }
        break;
    }

    case VK_DOWN: // Down arrow key.
    {
        if (m_dy != -m_height)
        {
            m_dy = m_height;
            m_dx = 0;
        }
        break;
    }

    case VK_LEFT: // Left arrow key.
    {
        if (m_dx != m_width) // Change to horizontal movement if the snake is currently moving vertically.
        {
            m_dx = -m_width;
            m_dy = 0;
        }
        break;
    }

    case VK_RIGHT: // Right arrow key.
    {
        if (m_dx != -m_width)
        {
            m_dx = m_width;
            m_dy = 0;
        }
        break;
    }
    }
}

bool Snake::collideWithSelf() const { return m_isCollided; }

std::pair<int, int> Snake::getHead() const { return m_body.front(); }

std::deque<std::pair<int, int>> Snake::getBody() const { return m_body; }

void Snake::draw(Renderer &renderer, const COLORREF &color)
{
    for (int i = 0; i < m_body.size(); i++)
        renderer.drawRectangle(m_body[i].first, m_body[i].second, m_width, m_height, color);
}

std::pair<int, int> Snake::adjustHead(const int &windowWidth, const int &windowHeight)
{
    std::pair<int, int> head = getHead();

    // If the new position exceeds the window boundaries, wrap around to the opposite side.
    if (head.first < 0)
        return std::make_pair(windowWidth - m_width, head.second);
    if (head.first >= windowWidth)
        return std::make_pair(0, head.second);
    if (head.second < 0)
        return std::make_pair(head.first, windowHeight - m_height);
    if (head.second >= windowHeight)
        return std::make_pair(head.first, 0);
    return std::make_pair(head.first + m_dx, head.second + m_dy);
}