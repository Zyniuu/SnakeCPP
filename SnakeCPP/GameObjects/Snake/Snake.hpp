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

class Snake : public GameObject
{
private:
    std::deque<std::pair<int, int>> m_body;
    std::unordered_set<std::pair<int, int>, pairHash> m_bodySet;
    int m_dx, m_dy;
    bool m_isGrowing;

public:
    Snake(const int &x, const int &y, const int &width, const int &height);

    void update();
    void grow();
    void handleInput(WPARAM keyCode);
    bool collideWithSelf() const;
    std::pair<int, int> getHead() const;
    std::deque<std::pair<int, int>> getBody() const;
    void draw(const HDC &hdc, const HBRUSH &brush) override;
};

#endif