---
title: Base/Window/Window.hpp

---

# Base/Window/Window.hpp



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Window](Classes/class_window.md)** <br>Represents the game window.  |




## Source code

```cpp


#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../Controllers/GameController/GameController.hpp"
#include "../Controllers/Renderer/WindowRenderer/WindowRenderer.hpp"
#include <string>
#include <atomic>
#include <thread>

class Window
{
private:
    HWND m_hwnd;                                      
    HDC m_memoryDC;                                   
    HBITMAP m_memoryBitmap;                           
    WPARAM m_lastKey;                                 
    bool m_isInputPending;                            
    std::string m_title;                              
    std::atomic<bool> m_isRunning;                    
    std::thread m_updateThread;                       
    std::unique_ptr<GameController> m_gameController; 
    std::unique_ptr<WindowRenderer> m_windowRenderer; 

public:
    Window(const std::string &title);

    ~Window();

    bool create(const HINSTANCE &hInstance);

    void show(const int &nCmdShow);

    void run();

private:
    void update();

    void initDoubleBuffering();

    LRESULT handleMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);

    static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif
```
