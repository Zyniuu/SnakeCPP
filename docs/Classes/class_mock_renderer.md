---
title: MockRenderer
summary: Mock class used for testing. 

---

# MockRenderer



Mock class used for testing.  [More...](#detailed-description)


`#include <MockRenderer.hpp>`

Inherits from [Renderer](Classes/class_renderer.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[clear](Classes/class_mock_renderer.md#function-clear)**(const COLORREF & color) |
| virtual void | **[drawRectangle](Classes/class_mock_renderer.md#function-drawrectangle)**(const int & x, const int & y, const int & width, const int & height, const COLORREF & color) override |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[drawCalls](Classes/class_mock_renderer.md#variable-drawcalls)**  |
| int | **[clearCalls](Classes/class_mock_renderer.md#variable-clearcalls)**  |

## Detailed Description

```cpp
class MockRenderer;
```

Mock class used for testing. 



## Public Functions Documentation

### function clear

```cpp
inline virtual void clear(
    const COLORREF & color
)
```


**Reimplements**: [Renderer::clear](Classes/class_renderer.md#function-clear)


### function drawRectangle

```cpp
inline virtual void drawRectangle(
    const int & x,
    const int & y,
    const int & width,
    const int & height,
    const COLORREF & color
) override
```


**Reimplements**: [Renderer::drawRectangle](Classes/class_renderer.md#function-drawrectangle)


## Public Attributes Documentation

### variable drawCalls

```cpp
int drawCalls = 0;
```


### variable clearCalls

```cpp
int clearCalls = 0;
```
