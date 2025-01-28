# Base/Controllers/Renderer/MockRenderer/MockRenderer.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[MockRenderer](Classes/class_mock_renderer.md)** <br>Mock class used for testing.  |




## Source code

```cpp


#ifndef MOCKRENDERER_HPP
#define MOCKRENDERER_HPP

#include "../Common/Renderer.hpp"

class MockRenderer : public Renderer
{
public:
    int drawCalls = 0;
    int clearCalls = 0;

    void clear(const COLORREF &color)
    {
        clearCalls++;
    }

    void drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color) override
    {
        drawCalls++;
    }
};

#endif
```
