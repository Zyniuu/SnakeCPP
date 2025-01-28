#include <gtest/gtest.h>
#include <algorithm>
#include "../../SnakeCPP/GameObjects/Fruit/Fruit.hpp"
#include "../../SnakeCPP/Base/Controllers/Renderer/Common/Renderer.hpp"

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
    class MockRenderer : public Renderer
    {
    public:
        int drawCalls = 0;

        void clear(const COLORREF &color)
        {
            return;
        }

        void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) override
        {
            drawCalls++;
        }
    };

    Fruit fruit(20, 20);
    MockRenderer mockRenderer; // Create a mock renderer

    // Draw the fruit with a red color
    fruit.draw(mockRenderer, RGB(255, 0, 0));
    EXPECT_EQ(mockRenderer.drawCalls, 1); // Should be one call made
}