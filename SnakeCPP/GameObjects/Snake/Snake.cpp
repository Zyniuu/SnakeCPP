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

Snake::Snake(const int &x, const int &y, const int &width, const int &height)
    : GameObject(width, height), m_dx(0), m_dy(height), m_isGrowing(false)
{
    m_body.push_back({x * width, y * height});
    m_bodySet.insert({x * width, y * height});
}

void Snake::update()
{
    std::pair<int, int> head = getHead();
    std::pair<int, int> newHead = std::make_pair(head.first + m_dx, head.second + m_dy);

    m_body.push_front(newHead);
    m_bodySet.insert(newHead);

    if (!m_isGrowing)
    {
        std::pair<int, int> tail = m_body.back();
        m_body.pop_back();
        m_bodySet.erase(tail);
    }
    else
        m_isGrowing = false;
}

void Snake::grow() { m_isGrowing = true; }

void Snake::handleInput(WPARAM keyCode)
{
    switch (keyCode)
    {
    case VK_UP:
    {
        m_dy = -m_height;
        m_dx = 0;
        break;
    }

    case VK_DOWN:
    {
        m_dy = m_height;
        m_dx = 0;
        break;
    }

    case VK_LEFT:
    {
        m_dx = -m_width;
        m_dy = 0;
        break;
    }

    case VK_RIGHT:
    {
        m_dx = m_width;
        m_dy = 0;
        break;
    }
    }
}

bool Snake::collideWithSelf() const
{
    std::pair<int, int> head = getHead();
    return m_bodySet.count(head) > 1;
}

std::pair<int, int> Snake::getHead() const { return m_body.front(); }

std::deque<std::pair<int, int>> Snake::getBody() const { return m_body; }

void Snake::draw(const HDC &hdc, const HBRUSH &brush)
{
    for (int i = 0; i < m_body.size(); i++)
    {
        int x = m_body[i].first;
        int y = m_body[i].second;
        RECT rect = {x, y, x + m_width, y + m_height};
        FillRect(hdc, &rect, brush);
    }
}