---
title: GameObjects/Snake/Snake.hpp

---

# GameObjects/Snake/Snake.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Snake](Classes/class_snake.md)** <br>Represents the snake in the game.  |




## Source code

```cpp


#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "../Common/GameObject.hpp"

class Snake : public GameObject
{
private:
    std::deque<std::pair<int, int>> m_body;                      
    std::unordered_set<std::pair<int, int>, pairHash> m_bodySet; 
    int m_dx, m_dy;                                              
    bool m_isGrowing;                                            
    bool m_isCollided;                                           

public:
    Snake(const int &x, const int &y, const int &width, const int &height);

    void update(const int &windowWidth, const int &windowHeight);

    void grow();

    void handleInput(const WPARAM &keyCode);

    bool collideWithSelf() const;

    std::pair<int, int> getHead() const;

    std::deque<std::pair<int, int>> getBody() const;

    void draw(class Renderer &renderer, const COLORREF &color) override;

private:
    std::pair<int, int> adjustHead(const int &windowWidth, const int &windowHeight);
};

#endif
```
