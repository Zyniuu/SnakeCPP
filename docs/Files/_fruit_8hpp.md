---
title: GameObjects/Fruit/Fruit.hpp

---

# GameObjects/Fruit/Fruit.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Fruit](Classes/class_fruit.md)** <br>Represents the fruit in the game.  |




## Source code

```cpp


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

    void draw(class Renderer &renderer, const COLORREF &color) override;
};

#endif
```
