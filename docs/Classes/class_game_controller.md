# GameController



Manages the logic of the game, including the snake, fruit, and collisions.  [More...](#detailed-description)


`#include <GameController.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[GameController](Classes/class_game_controller.md#function-gamecontroller)**()<br>Initializes the game (creates snake and fruit).  |
| void | **[handleInput](Classes/class_game_controller.md#function-handleinput)**(const WPARAM & keyCode)<br>Handles player input.  |
| bool | **[update](Classes/class_game_controller.md#function-update)**()<br>Updates the game state (moves snake, checks collisions).  |
| void | **[render](Classes/class_game_controller.md#function-render)**(class [Renderer](Classes/class_renderer.md) & renderer)<br>Renders the game objects using the provided renderer.  |

## Detailed Description

```cpp
class GameController;
```

Manages the logic of the game, including the snake, fruit, and collisions. 



## Public Functions Documentation

### function GameController

```cpp
GameController()
```

Initializes the game (creates snake and fruit). 




### function handleInput

```cpp
void handleInput(
    const WPARAM & keyCode
)
```

Handles player input. 

**Parameters**: 

  * **keyCode** The virtual key code of the pressed key. 


### function update

```cpp
bool update()
```

Updates the game state (moves snake, checks collisions). 

**Return**: True if the game should continue, false if it's game over. 

### function render

```cpp
void render(
    class Renderer & renderer
)
```

Renders the game objects using the provided renderer. 

**Parameters**: 

  * **renderer** [Renderer](Classes/class_renderer.md) used to draw on the window. 
