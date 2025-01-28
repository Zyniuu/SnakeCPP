---
title: Base/Controllers/Renderer/WindowRenderer/WindowRenderer.cpp

---

# Base/Controllers/Renderer/WindowRenderer/WindowRenderer.cpp






## Source code

```cpp


#include "WindowRenderer.hpp"
#include "../../../Constants/Constants.hpp"

WindowRenderer::WindowRenderer(const HDC &hdc) : m_hdc(hdc) {}

WindowRenderer::~WindowRenderer()
{
    // Delete device context.
    if (m_hdc)
    {
        DeleteObject(m_hdc);
        m_hdc = nullptr;
    }

    // Delete all created brushes.
    for (auto &[color, brush] : m_brushes)
        DeleteObject(brush);
    m_brushes.clear();
}

void WindowRenderer::clear(const COLORREF &color)
{
    RECT rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}; // Rectangle representing the window.
    FillRect(m_hdc, &rect, getBrush(color));         // Fill the whole window using the brush.
}

void WindowRenderer::drawRectangle(const int &x, const int &y, const int &width, const int &height, const COLORREF &color)
{
    RECT rect = {x, y, x + width, y + height}; // Rectangle with the specified size and position.
    FillRect(m_hdc, &rect, getBrush(color));   // Fill the specified rectangle using the brush.
}

HBRUSH WindowRenderer::getBrush(const COLORREF &color)
{
    auto it = m_brushes.find(color); // Look for the brush.

    if (it != m_brushes.end())
        return it->second; // Return if exists.

    HBRUSH brush = CreateSolidBrush(color); // If not, create a new one.
    m_brushes[color] = brush;               // Add it to the collection.
    return brush;
}
```
