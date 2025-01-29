# main.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int WINAPI | **[WinMain](main_8cpp.md#function-winmain)**(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) |


## Functions Documentation

### function WinMain

```cpp
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
```




## Source code

```cpp


#include "Base/Window/Window.hpp"

// The entry point for a Windows application.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Create the main window
    Window mainWindow("SnakeCPP");

    // Check if the window was created successfully
    if (!mainWindow.create(hInstance))
        return -1;

    // Show the window
    mainWindow.show(nCmdShow);

    // Run the main application loop
    mainWindow.run();

    return 0;
}
```