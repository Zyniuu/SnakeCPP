---
title: Base/Controllers/Renderer/Common/Renderer.hpp

---

# Base/Controllers/Renderer/Common/Renderer.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Renderer](Classes/class_renderer.md)** <br>Abstracts rendering logic to allow testing.  |




## Source code

```cpp


#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <windows.h>

class Renderer
{
public:
    virtual void clear(const COLORREF &color) = 0;
    virtual void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) = 0;
};

#endif
```