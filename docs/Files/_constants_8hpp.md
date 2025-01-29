# Base/Constants/Constants.hpp



## Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[WINDOW_WIDTH](_constants_8hpp.md#variable-window-width)** <br>The width of the game window in pixels.  |
| int | **[WINDOW_HEIGHT](_constants_8hpp.md#variable-window-height)** <br>The height of the game window in pixels.  |
| int | **[ROWS](_constants_8hpp.md#variable-rows)** <br>The number of rows in the game grid.  |
| int | **[COLS](_constants_8hpp.md#variable-cols)** <br>The number of columns in the game grid.  |
| int | **[FPS](_constants_8hpp.md#variable-fps)** <br>The frame rate of the game in frames per second.  |
| COLORREF | **[BACKGROUND_COLOR](_constants_8hpp.md#variable-background-color)** <br>The background color of the game window.  |
| COLORREF | **[SNAKE_COLOR](_constants_8hpp.md#variable-snake-color)** <br>The color of the snake.  |
| COLORREF | **[FRUIT_COLOR](_constants_8hpp.md#variable-fruit-color)** <br>The color of the fruit.  |



## Attributes Documentation

### variable WINDOW_WIDTH

```cpp
int WINDOW_WIDTH = 450;
```

The width of the game window in pixels. 


### variable WINDOW_HEIGHT

```cpp
int WINDOW_HEIGHT = 705;
```

The height of the game window in pixels. 

### variable ROWS

```cpp
int ROWS = 47;
```

The number of rows in the game grid. 

### variable COLS

```cpp
int COLS = 30;
```

The number of columns in the game grid. 

### variable FPS

```cpp
int FPS = 30;
```

The frame rate of the game in frames per second. 

### variable BACKGROUND_COLOR

```cpp
COLORREF BACKGROUND_COLOR = RGB(44, 62, 80);
```

The background color of the game window. 

### variable SNAKE_COLOR

```cpp
COLORREF SNAKE_COLOR = RGB(236, 240, 241);
```

The color of the snake. 

### variable FRUIT_COLOR

```cpp
COLORREF FRUIT_COLOR = RGB(192, 57, 43);
```

The color of the fruit. 


## Source code

```cpp


#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <windows.h>

constexpr int WINDOW_WIDTH = 450;  
constexpr int WINDOW_HEIGHT = 705; 
constexpr int ROWS = 47;           
constexpr int COLS = 30;           
constexpr int FPS = 30;            

constexpr COLORREF BACKGROUND_COLOR = RGB(44, 62, 80); 
constexpr COLORREF SNAKE_COLOR = RGB(236, 240, 241);   
constexpr COLORREF FRUIT_COLOR = RGB(192, 57, 43);     

#endif
```
