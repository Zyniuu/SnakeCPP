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
 * TestSnake.cpp
 */

#include <gtest/gtest.h>
#include "../../SnakeCPP/GameObjects/Snake/Snake.hpp"
#include "../../SnakeCPP/Base/Controllers/Renderer/MockRenderer/MockRenderer.hpp"

// Test case: Initialization
TEST(SnakeTests, InitializesProperly)
{
    Snake snake(0, 0, 10, 10);

    // Check if initial size of snake is 1
    EXPECT_EQ(snake.getBody().size(), 1);

    // Check if initial position of the head is (0, 0)
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 0));
}

// Test case: handleInput changes direction
TEST(SnakeTests, HandleInputChangesDirection)
{
    Snake snake(10, 10, 10, 10);

    // Right
    snake.handleInput(VK_RIGHT);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(20, 10));

    // Up
    snake.handleInput(VK_UP);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(20, 0));

    // Left
    snake.handleInput(VK_LEFT);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(10, 0));

    // Down
    snake.handleInput(VK_DOWN);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(10, 10));
}

// Test case: Grows correctly
TEST(SnakeTests, GrowsCorrectly)
{
    Snake snake(0, 0, 10, 10);

    // Simulate growth and movement
    snake.grow();
    snake.update(100, 100);

    // Check if size increased
    EXPECT_EQ(snake.getBody().size(), 2);

    // Check if snake segments are at correct positions
    auto body = snake.getBody();
    EXPECT_EQ(body[0], std::make_pair(0, 10)); // Head
    EXPECT_EQ(body[1], std::make_pair(0, 0));  // Tail
}

// Test case: Detects collision
TEST(SnakeTests, DetectsSelfCollision)
{
    Snake snake(0, 0, 10, 10);

    // Snake is growing to create a loop
    snake.grow();
    snake.update(100, 100);
    snake.handleInput(VK_RIGHT);
    snake.grow();
    snake.update(100, 100);
    snake.handleInput(VK_DOWN);
    snake.grow();
    snake.update(100, 100);
    snake.handleInput(VK_LEFT);
    snake.grow();
    snake.update(100, 100);
    snake.handleInput(VK_UP);
    snake.update(100, 100);

    // Check if collision was detected
    EXPECT_TRUE(snake.collideWithSelf());
}

// Test case: Wraps around the window
TEST(SnakeTests, WrapsAroundWindow)
{
    Snake snake(90, 90, 10, 10); // Initial position close to the border

    // Move right (outside the border)
    snake.handleInput(VK_RIGHT);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 90));

    // Move down (outside the border)
    snake.handleInput(VK_DOWN);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 0));
}

// Test case: Ignores invalid input
TEST(SnakeTests, IgnoresInvalidInput)
{
    Snake snake(0, 0, 10, 10);

    // Down
    snake.handleInput(VK_DOWN);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 10));

    // Up (not allowed when going down)
    snake.handleInput(VK_UP);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 20)); // Still down
}

// Test case: Handles different segment sizes
TEST(SnakeTests, HandlesDifferentSegmentSizes)
{
    Snake snake(0, 0, 20, 20);

    snake.handleInput(VK_DOWN);
    snake.update(100, 100);
    EXPECT_EQ(snake.getHead(), std::make_pair(0, 20)); // Bigger segment
}

// Test case: Draw calls renderer correctly
TEST(SnakeTests, DrawCallsRendererCorrectly)
{
    Snake snake(10, 10, 10, 10);
    MockRenderer mockRenderer;

    snake.draw(mockRenderer, RGB(0, 255, 0));
    EXPECT_EQ(mockRenderer.drawCalls, 1); // Should be one call made
}