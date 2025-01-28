# Base/Controllers/Renderer/WindowRenderer/WindowRenderer.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[WindowRenderer](Classes/class_window_renderer.md)** <br>Handles the window rendering logic.  |




## Source code

```cpp


#ifndef WINDOWRENDERER_HPP
#define WINDOWRENDERER_HPP

#include "../Common/Renderer.hpp"
#include <unordered_map>

class WindowRenderer : public Renderer
{
private:
    HDC m_hdc;                                      
    std::unordered_map<COLORREF, HBRUSH> m_brushes; 

public:
    WindowRenderer(const HDC &hdc);

    ~WindowRenderer();

    void clear(const COLORREF &color) override;

    void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) override;

private:
    HBRUSH getBrush(const COLORREF &color);
};

#endif
```
