# Renderer



Abstracts rendering logic to allow testing.  [More...](#detailed-description)


`#include <Renderer.hpp>`

Inherited by [MockRenderer](class_mock_renderer.md), [WindowRenderer](class_window_renderer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[clear](class_renderer.md#function-clear)**(const COLORREF & color) =0 |
| virtual void | **[drawRectangle](class_renderer.md#function-drawrectangle)**(const int & x, const int & y, const int & width, const int & height, const COLORREF & color) =0 |

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


**Reimplemented by**: [MockRenderer::clear](class_mock_renderer.md#function-clear), [WindowRenderer::clear](class_window_renderer.md#function-clear)


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


**Reimplemented by**: [MockRenderer::drawRectangle](class_mock_renderer.md#function-drawrectangle), [WindowRenderer::drawRectangle](class_window_renderer.md#function-drawrectangle)

