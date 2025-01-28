# Base/Controllers/GameController/GameController.cpp






## Source code

```cpp


#include "GameController.hpp"
#include "../Renderer/Common/Renderer.hpp"
#include "../../Constants/Constants.hpp"

GameController::GameController()
{
    int cellWidth = WINDOW_WIDTH / COLS;
    int cellHeight = WINDOW_HEIGHT / ROWS;

    // Initialize snake in the center.
    int startX = (COLS / 2) * cellWidth;
    int startY = (ROWS / 2) * cellHeight;
    m_snake = std::make_unique<Snake>(startX, startY, cellWidth, cellHeight);

    // Initialize fruit.
    m_fruit = std::make_unique<Fruit>(cellWidth, cellHeight);
    m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
}

void GameController::handleInput(const WPARAM &keyCode)
{
    if (m_snake)
        m_snake->handleInput(keyCode);
}

bool GameController::update()
{
    if (!m_snake || !m_fruit)
        return false;

    // Move snake and check collisions
    m_snake->update(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Chceck if snake's body fills the whole window
    if (m_snake->getBody().size() >= COLS * ROWS)
        return false;

    if (m_snake->getHead() == m_fruit->getPosition())
    {
        m_snake->grow();
        m_fruit->regenerate(COLS, ROWS, m_snake->getBody());
    }

    return !m_snake->collideWithSelf(); // Return false if game over.
}

void GameController::render(Renderer &renderer)
{
    if (m_fruit)
        m_fruit->draw(renderer, FRUIT_COLOR);

    if (m_snake)
        m_snake->draw(renderer, SNAKE_COLOR);
}
```
