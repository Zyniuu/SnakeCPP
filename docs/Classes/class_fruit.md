# Fruit



Represents the fruit in the game.  [More...](#detailed-description)


`#include <Fruit.hpp>`

Inherits from [GameObject](Classes/class_game_object.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Fruit](Classes/class_fruit.md#function-fruit)**(const int & width, const int & height)<br>Constructs a [Fruit](Classes/class_fruit.md) object.  |
| std::pair< int, int > | **[getPosition](Classes/class_fruit.md#function-getposition)**() const<br>Gets the position of the fruit.  |
| void | **[regenerate](Classes/class_fruit.md#function-regenerate)**(const int & cols, const int & rows, const std::deque< std::pair< int, int > > & snakeBody)<br>Regenerates the fruit at a new position not occupied by the snake.  |
| virtual void | **[draw](Classes/class_fruit.md#function-draw)**(class [Renderer](Classes/class_renderer.md) & renderer, const COLORREF & color) override<br>Draws the fruit on the screen.  |

## Additional inherited members

**Protected Classes inherited from [GameObject](Classes/class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| struct | **[pairHash](Classes/struct_game_object_1_1pair_hash.md)** <br>A custom hash function for pairs.  |

**Public Functions inherited from [GameObject](Classes/class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| | **[GameObject](Classes/class_game_object.md#function-gameobject)**(const int & width, const int & height)<br>Constructs a [GameObject](Classes/class_game_object.md).  |

**Protected Attributes inherited from [GameObject](Classes/class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| int | **[m_width](Classes/class_game_object.md#variable-m-width)** <br>The width of the object.  |
| int | **[m_height](Classes/class_game_object.md#variable-m-height)** <br>The height of the object.  |


## Detailed Description

```cpp
class Fruit;
```

Represents the fruit in the game. 



## Public Functions Documentation

### function Fruit

```cpp
Fruit(
    const int & width,
    const int & height
)
```

Constructs a [Fruit](Classes/class_fruit.md) object. 

**Parameters**: 

  * **width** The width of the fruit. 
  * **height** The height of the fruit.





### function getPosition

```cpp
std::pair< int, int > getPosition() const
```

Gets the position of the fruit. 

**Return**: A pair representing the x and y coordinates of the fruit. 

### function regenerate

```cpp
void regenerate(
    const int & cols,
    const int & rows,
    const std::deque< std::pair< int, int > > & snakeBody
)
```

Regenerates the fruit at a new position not occupied by the snake. 

**Parameters**: 

  * **cols** The number of columns in the game grid. 
  * **rows** The number of rows in the game grid. 
  * **snakeBody** The current body of the snake. 


### function draw

```cpp
virtual void draw(
    class Renderer & renderer,
    const COLORREF & color
) override
```

Draws the fruit on the screen. 

**Parameters**: 

  * **renderer** [Renderer](Classes/class_renderer.md) used to draw on the window. 
  * **color** Color of the fruit. 


**Reimplements**: [GameObject::draw](Classes/class_game_object.md#function-draw)
