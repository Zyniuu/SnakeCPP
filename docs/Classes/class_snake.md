# Snake



Represents the snake in the game.  [More...](#detailed-description)


`#include <Snake.hpp>`

Inherits from [GameObject](class_game_object.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Snake](class_snake.md#function-snake)**(const int & x, const int & y, const int & width, const int & height)<br>Constructs a [Snake](class_snake.md) object.  |
| void | **[update](class_snake.md#function-update)**(const int & windowWidth, const int & windowHeight)<br>Updates the snake's position and checks for collisions.  |
| void | **[grow](class_snake.md#function-grow)**()<br>Grows the snake by one segment.  |
| void | **[handleInput](class_snake.md#function-handleinput)**(const WPARAM & keyCode)<br>Handles user input to change the snake's direction.  |
| bool | **[collideWithSelf](class_snake.md#function-collidewithself)**() const<br>Checks if the snake has collided with itself.  |
| std::pair< int, int > | **[getHead](class_snake.md#function-gethead)**() const<br>Gets the position of the snake's head.  |
| std::deque< std::pair< int, int > > | **[getBody](class_snake.md#function-getbody)**() const<br>Gets the body of the snake.  |
| virtual void | **[draw](class_snake.md#function-draw)**(class [Renderer](class_renderer.md) & renderer, const COLORREF & color) override<br>Draws the snake on the screen.  |

## Additional inherited members

**Protected Classes inherited from [GameObject](class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| struct | **[pairHash](struct_game_object_1_1pair_hash.md)** <br>A custom hash function for pairs.  |

**Public Functions inherited from [GameObject](class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| | **[GameObject](class_game_object.md#function-gameobject)**(const int & width, const int & height)<br>Constructs a [GameObject](class_game_object.md).  |

**Protected Attributes inherited from [GameObject](class_game_object.md)**

|                | Name           |
| -------------- | -------------- |
| int | **[m_width](class_game_object.md#variable-m-width)** <br>The width of the object.  |
| int | **[m_height](class_game_object.md#variable-m-height)** <br>The height of the object.  |


## Detailed Description

```cpp
class Snake;
```

Represents the snake in the game. 


## Public Functions Documentation

### function Snake

```cpp
Snake(
    const int & x,
    const int & y,
    const int & width,
    const int & height
)
```

Constructs a [Snake](class_snake.md) object. 

**Parameters**: 

  * **x** The initial x-coordinate of the snake's head. 
  * **y** The initial y-coordinate of the snake's head. 
  * **width** The width of each segment of the snake. 
  * **height** The height of each segment of the snake.




### function update

```cpp
void update(
    const int & windowWidth,
    const int & windowHeight
)
```

Updates the snake's position and checks for collisions. 

**Parameters**: 

  * **windowWidth** The width of the game window. 
  * **windowHeight** The height of the game window. 


### function grow

```cpp
void grow()
```

Grows the snake by one segment. 

### function handleInput

```cpp
void handleInput(
    const WPARAM & keyCode
)
```

Handles user input to change the snake's direction. 

**Parameters**: 

  * **keyCode** The virtual key code of the pressed key. 


### function collideWithSelf

```cpp
bool collideWithSelf() const
```

Checks if the snake has collided with itself. 

**Return**: True if the snake has collided, false otherwise. 

### function getHead

```cpp
std::pair< int, int > getHead() const
```

Gets the position of the snake's head. 

**Return**: A pair representing the x and y coordinates of the head. 

### function getBody

```cpp
std::deque< std::pair< int, int > > getBody() const
```

Gets the body of the snake. 

**Return**: A deque representing the snake's body segments. 

### function draw

```cpp
virtual void draw(
    class Renderer & renderer,
    const COLORREF & color
) override
```

Draws the snake on the screen. 

**Parameters**: 

  * **renderer** [Renderer](class_renderer.md) used to draw on the window. 
  * **color** Color of the snake. 


**Reimplements**: [GameObject::draw](class_game_object.md#function-draw)
