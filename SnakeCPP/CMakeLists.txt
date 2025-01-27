# Minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name
project(SnakeCPP)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type at Release
set(CMAKE_BUILD_TYPE Release)

# Project source files
set(SOURCES
    main.cpp
    Base/Window/Window.cpp
    Base/Controllers/Renderer/WindowRenderer/WindowRenderer.cpp
    Base/Controllers/GameController/GameController.cpp
    GameObjects/Snake/Snake.cpp
    GameObjects/Fruit/Fruit.cpp
)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Windows flags setup
target_link_libraries(${PROJECT_NAME} PRIVATE user32 gdi32)
target_link_options(${PROJECT_NAME} PRIVATE -mwindows)

# Header files linkage
target_include_directories(${PROJECT_NAME} PRIVATE
    Base/Window
    Base/Constants
    Base/Controllers/Renderer/Common
    Base/Controllers/Renderer/WindowRenderer
    Base/Controllers/GameController
    GameObjects/Common
    GameObjects/Snake
    GameObjects/Fruit
)

# Setting up compilator flags for release build
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
endif()