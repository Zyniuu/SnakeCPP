# WindowRenderer



Handles the window rendering logic.  [More...](#detailed-description)


`#include <WindowRenderer.hpp>`

Inherits from [Renderer](class_renderer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[WindowRenderer](class_window_renderer.md#function-windowrenderer)**(const HDC & hdc)<br>Constructs the window renderer.  |
| | **[~WindowRenderer](class_window_renderer.md#function-~windowrenderer)**()<br>Releases recources of the renderer.  |
| virtual void | **[clear](class_window_renderer.md#function-clear)**(const COLORREF & color) override<br>Clears the window with a specified background color.  |
| virtual void | **[drawRectangle](class_window_renderer.md#function-drawrectangle)**(const int & x, const int & y, const int & width, const int & height, const COLORREF & color) override<br>Draws rectangle on the window with a specified color.  |

## Detailed Description

```cpp
class WindowRenderer;
```

Handles the window rendering logic. 


## Public Functions Documentation

### function WindowRenderer

```cpp
WindowRenderer(
    const HDC & hdc
)
```

Constructs the window renderer. 

**Parameters**: 

  * **hdc** Device context to draw on.




### function ~WindowRenderer

```cpp
~WindowRenderer()
```

Releases recources of the renderer. 

### function clear

```cpp
virtual void clear(
    const COLORREF & color
) override
```

Clears the window with a specified background color. 

**Parameters**: 

  * **color** [Window](class_window.md) background color. 


**Reimplements**: [Renderer::clear](class_renderer.md#function-clear)


### function drawRectangle

```cpp
virtual void drawRectangle(
    const int & x,
    const int & y,
    const int & width,
    const int & height,
    const COLORREF & color
) override
```

Draws rectangle on the window with a specified color. 

**Parameters**: 

  * **x** X coordinate of the rectangle. 
  * **y** Y coordinate of the rectangle. 
  * **width** Width of the rectangle. 
  * **height** Height of the rectangle. 
  * **color** Color of the rectangle 


**Reimplements**: [Renderer::drawRectangle](class_renderer.md#function-drawrectangle)
