# Base/Controllers/GameController/GameController.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[GameController](Classes/class_game_controller.md)** <br>Manages the logic of the game, including the snake, fruit, and collisions.  |




## Source code

```cpp


#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "../../../GameObjects/Snake/Snake.hpp"
#include "../../../GameObjects/Fruit/Fruit.hpp"
#include <memory>

class GameController
{
private:
    std::unique_ptr<Snake> m_snake; 
    std::unique_ptr<Fruit> m_fruit; 

public:
    GameController();

    void handleInput(const WPARAM &keyCode);

    bool update();

    void render(class Renderer &renderer);
};

#endif
```
