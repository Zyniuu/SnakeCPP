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
 * TestGameController.cpp
 */

#include <gtest/gtest.h>
#include "../../SnakeCPP/Base/Controllers/GameController/GameController.hpp"
#include "../../SnakeCPP/Base/Controllers/Renderer/MockRenderer/MockRenderer.hpp"

// Test case: Game controller initializes properly
TEST(GameControllerTests, InitializesCorrectly)
{
    std::unique_ptr<GameController> gc = std::make_unique<GameController>();
    ASSERT_NE(gc, nullptr);
}

// Test case: update() continues the game when no collision occur
TEST(GameControllerTests, UpdateContinuesGame)
{
    std::unique_ptr<GameController> gc = std::make_unique<GameController>();
    EXPECT_TRUE(gc->update());
}

// Test case: Ensure GameController passes input to the snake correctly
TEST(GameControllerTests, HandleInput)
{
    std::unique_ptr<GameController> gc = std::make_unique<GameController>();
    EXPECT_NO_THROW(gc->handleInput(VK_RIGHT));
}

// Test case: rendering calls draw method for both snake and fruit
TEST(GameControllerTests, RenderCallsDrawMethods)
{
    std::unique_ptr<GameController> gc = std::make_unique<GameController>();
    MockRenderer mockRenderer;

    gc->render(mockRenderer);

    EXPECT_EQ(mockRenderer.drawCalls, 2);
}