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
 * GameObject.hpp
 */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <windows.h>
#include <unordered_set>
#include <deque>

class GameObject
{
protected:
    int m_width;
    int m_height;

    struct pairHash
    {
        template <typename T1, typename T2>
        size_t operator()(const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

public:
    GameObject(const int &width, const int &height)
        : m_width(width), m_height(height) {}

    virtual void draw(const HDC &hdc, const HBRUSH &brush) = 0;
};

#endif