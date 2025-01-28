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
 * TestFruit.cpp
 */

#include <gtest/gtest.h>
#include <algorithm>
#include "../../SnakeCPP/GameObjects/Fruit/Fruit.hpp"
#include "../../SnakeCPP/Base/Controllers/Renderer/MockRenderer/MockRenderer.hpp"

// Test case: The constructor initializes the fruit correctly
TEST(FruitTests, ConstructorInitializesCorrectly) {
    Fruit fruit(20, 20);
    std::pair<int, int> initialPosition = fruit.getPosition();
    EXPECT_EQ(initialPosition.first, 0);
    EXPECT_EQ(initialPosition.second, 0);
}

// Test case: regenerate() places the fruit at a valid position
TEST(FruitTests, RegeneratePlacesFruitCorrectly) 
{
    Fruit fruit(20, 20);

    // Game grid dimensions
    int cols = 10;
    int rows = 10;

    // Simulate snake body occupying some grid cells
    std::deque<std::pair<int, int>> snakeBody = {
        {0, 0}, {20, 0}, {40, 0}
    };

    // Call regenerate
    fruit.regenerate(cols, rows, snakeBody);

    // Get fruit's new position
    std::pair<int, int> fruitPosition = fruit.getPosition();

    // Check if fruit's position is inside the grid
    EXPECT_GE(fruitPosition.first, 0);
    EXPECT_LT(fruitPosition.first, cols * 20);
    EXPECT_GE(fruitPosition.second, 0);
    EXPECT_LT(fruitPosition.second, rows * 20);

    // Ensure fruit's position does not overlap with the snake's body
    EXPECT_EQ(std::count(snakeBody.begin(), snakeBody.end(), fruitPosition), 0);
}

// Test case: regenerate avoids snake collisions
TEST(FruitTests, RegenerateAvoidsSnakeBody) 
{
    Fruit fruit(20, 20);

    int cols = 5;
    int rows = 5;

    // Simulate a snake occupying all grid cells except one
    std::deque<std::pair<int, int>> snakeBody = {
        {0, 0}, {0, 20}, {0, 40}, {0, 60}, {0, 80},
        {20, 0}, {20, 20}, {20, 40}, {20, 60}, {20, 80},
        {40, 0}, {40, 20}, {40, 60}, {40, 80}, {60, 0},
        {60, 20}, {60, 40}, {60, 60}, {60, 80}, {80, 0},
        {80, 20}, {80, 40}, {80, 60}, {80, 80} // Snake fills almost all cells
    };

    // Remaining cell is at (40, 40)
    fruit.regenerate(cols, rows, snakeBody);

    // Check that the fruit is at the only unoccupied position
    EXPECT_EQ(fruit.getPosition(), std::make_pair(40, 40));
}

// Test case: The draw() function calls Renderer correctly
TEST(FruitTests, DrawCallsRenderer) 
{
    Fruit fruit(20, 20);
    MockRenderer mockRenderer; // Create a mock renderer

    // Draw the fruit with a red color
    fruit.draw(mockRenderer, RGB(255, 0, 0));
    EXPECT_EQ(mockRenderer.drawCalls, 1); // Should be one call made
}