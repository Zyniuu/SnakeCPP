# Minimum required CMake version
cmake_minimum_required(VERSION 3.15)

# Project name
project(SnakeCPP)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project source files
set(SOURCES
    main.cpp
    Base/Window/Window.cpp
    GameObjects/Snake/Snake.cpp
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
    GameObjects/Common
    GameObjects/Snake
)