# Window



Represents the game window.  [More...](#detailed-description)


`#include <Window.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Window](class_window.md#function-window)**(const std::string & title)<br>Constructs the game window with the specified title.  |
| | **[~Window](class_window.md#function-~window)**()<br>Destroys the game window and releases resources.  |
| bool | **[create](class_window.md#function-create)**(const HINSTANCE & hInstance)<br>Creates the game window.  |
| void | **[show](class_window.md#function-show)**(const int & nCmdShow)<br>Displays the game window.  |
| void | **[run](class_window.md#function-run)**()<br>Runs the main game loop.  |

## Detailed Description

```cpp
class Window;
```

Represents the game window. 

## Public Functions Documentation

### function Window

```cpp
Window(
    const std::string & title
)
```

Constructs the game window with the specified title. 

**Parameters**: 

  * **title** The title of the window.





### function ~Window

```cpp
~Window()
```

Destroys the game window and releases resources. 

### function create

```cpp
bool create(
    const HINSTANCE & hInstance
)
```

Creates the game window. 

**Parameters**: 

  * **hInstance** The handle to the application instance. 


**Return**: True if the window was successfully created, false otherwise. 

### function show

```cpp
void show(
    const int & nCmdShow
)
```

Displays the game window. 

**Parameters**: 

  * **nCmdShow** The show command for the window. 


### function run

```cpp
void run()
```

Runs the main game loop. 
