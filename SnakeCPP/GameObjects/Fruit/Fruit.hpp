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

class Fruit : public GameObject
{
private:
    int m_x, m_y;

public:
    Fruit(const int &width, const int &height);

    std::pair<int, int> getPosition() const;
    void regenerate(const int &cols, const int &rows, const std::deque<std::pair<int, int>> &snakeBody);
    void draw(const HDC &hdc, const HBRUSH &brush) override;
};

#endif