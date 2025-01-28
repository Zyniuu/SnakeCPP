---
title: GameObject
summary: Represents a base class for drawable objects in the game. 

---

# GameObject



Represents a base class for drawable objects in the game.  [More...](#detailed-description)


`#include <GameObject.hpp>`

Inherited by [Fruit](Classes/class_fruit.md), [Snake](Classes/class_snake.md)

## Protected Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[pairHash](Classes/struct_game_object_1_1pair_hash.md)** <br>A custom hash function for pairs.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[GameObject](Classes/class_game_object.md#function-gameobject)**(const int & width, const int & height)<br>Constructs a [GameObject](Classes/class_game_object.md).  |
| virtual void | **[draw](Classes/class_game_object.md#function-draw)**(class [Renderer](Classes/class_renderer.md) & renderer, const COLORREF & color) =0<br>Pure virtual function to draw the object on the screen.  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[m_width](Classes/class_game_object.md#variable-m-width)** <br>The width of the object.  |
| int | **[m_height](Classes/class_game_object.md#variable-m-height)** <br>The height of the object.  |

## Detailed Description

```cpp
class GameObject;
```

Represents a base class for drawable objects in the game. 



## Public Functions Documentation

### function GameObject

```cpp
inline GameObject(
    const int & width,
    const int & height
)
```

Constructs a [GameObject](Classes/class_game_object.md). 

**Parameters**: 

  * **width** The width of the object. 
  * **height** The height of the object. 


### function draw

```cpp
virtual void draw(
    class Renderer & renderer,
    const COLORREF & color
) =0
```

Pure virtual function to draw the object on the screen. 

**Parameters**: 

  * **renderer** [Renderer](Classes/class_renderer.md) used to draw on the window. 
  * **color** Color of the game object. 


**Reimplemented by**: [Fruit::draw](Classes/class_fruit.md#function-draw), [Snake::draw](Classes/class_snake.md#function-draw)


## Protected Attributes Documentation

### variable m_width

```cpp
int m_width;
```

The width of the object. 

### variable m_height

```cpp
int m_height;
```

The height of the object. 
