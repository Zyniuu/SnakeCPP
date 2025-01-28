# GameObjects/Common/GameObject.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[GameObject](Classes/class_game_object.md)** <br>Represents a base class for drawable objects in the game.  |




## Source code

```cpp


#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <windows.h>
#include <unordered_set>
#include <deque>

class GameObject
{
protected:
    int m_width;  
    int m_height; 

    struct pairHash
    {
        template <typename T1, typename T2>
        size_t operator()(const std::pair<T1, T2> &pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

public:
    GameObject(const int &width, const int &height)
        : m_width(width), m_height(height) {}

    virtual void draw(class Renderer &renderer, const COLORREF &color) = 0;
};

#endif
```
