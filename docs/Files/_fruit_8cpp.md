# GameObjects/Fruit/Fruit.cpp






## Source code

```cpp


#include "Fruit.hpp"
#include "../../Base/Controllers/Renderer/Common/Renderer.hpp"
#include <time.h>

Fruit::Fruit(const int &width, const int &height)
    : GameObject(width, height), m_x(0), m_y(0)
{
    srand(time(nullptr)); // Seed the random number generator with the current time.
}

std::pair<int, int> Fruit::getPosition() const { return std::make_pair(m_x, m_y); }

void Fruit::regenerate(const int &cols, const int &rows, const std::deque<std::pair<int, int>> &snakeBody)
{
    // Convert the snake's body into a hash set for efficient lookup of occupied positions.
    std::unordered_set<std::pair<int, int>, pairHash> snakeSet(snakeBody.begin(), snakeBody.end());

    do
    {
        // Generate a random position for the fruit within the grid dimensions.
        m_x = (rand() % cols) * m_width;  // Random column scaled by cell width.
        m_y = (rand() % rows) * m_height; // Random row scaled by cell height.
    } while (snakeSet.count(getPosition()) > 0); // Repeat if the position overlaps with any part of the snake's body.
}

void Fruit::draw(Renderer &renderer, const COLORREF &color)
{
    renderer.drawRectangle(m_x, m_y, m_width, m_height, color);
}
```

