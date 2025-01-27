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

/**
 * @class GameObject
 * @brief Represents a base class for drawable objects in the game.
 */
class GameObject
{
protected:
    int m_width;  // The width of the object.
    int m_height; // The height of the object.

    /**
     * @brief A custom hash function for pairs.
     */
    struct pairHash
    {
        template <typename T1, typename T2>
        size_t operator()(const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

public:
    /**
     * @brief Constructs a GameObject.
     *
     * @param width The width of the object.
     * @param height The height of the object.
     */
    GameObject(const int &width, const int &height)
        : m_width(width), m_height(height) {}

    /**
     * @brief Pure virtual function to draw the object on the screen.
     *
     * @param renderer Renderer used to draw on the window.
     * @param color Color of the game object.
     */
    virtual void draw(class Renderer &renderer, const COLORREF &color) = 0;
};

#endif