# Renderer



Abstracts rendering logic to allow testing.  [More...](#detailed-description)


`#include <Renderer.hpp>`

Inherited by [MockRenderer](Classes/class_mock_renderer.md), [WindowRenderer](Classes/class_window_renderer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[clear](Classes/class_renderer.md#function-clear)**(const COLORREF & color) =0 |
| virtual void | **[drawRectangle](Classes/class_renderer.md#function-drawrectangle)**(const int & x, const int & y, const int & width, const int & height, const COLORREF & color) =0 |

## Detailed Description

```cpp
class Renderer;
```

Abstracts rendering logic to allow testing. 



## Public Functions Documentation

### function clear

```cpp
virtual void clear(
    const COLORREF & color
) =0
```


**Reimplemented by**: [MockRenderer::clear](Classes/class_mock_renderer.md#function-clear), [WindowRenderer::clear](Classes/class_window_renderer.md#function-clear)


### function drawRectangle

```cpp
virtual void drawRectangle(
    const int & x,
    const int & y,
    const int & width,
    const int & height,
    const COLORREF & color
) =0
```


**Reimplemented by**: [MockRenderer::drawRectangle](Classes/class_mock_renderer.md#function-drawrectangle), [WindowRenderer::drawRectangle](Classes/class_window_renderer.md#function-drawrectangle)

