# Minimal version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(SnakeCPPTests)

# Enable testing
enable_testing()

# Add Google Test directory
add_subdirectory(googletest)

# List of source files for the tests
set(TEST_SOURCES
    GameObjects/TestSnake.cpp
    GameObjects/TestFruit.cpp
    Controllers/TestGameController.cpp
    tests.cpp
)

# Create the test executable
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Include directories for headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ../SnakeCPP/Base/Constants
    ../SnakeCPP/Base/Controllers/Renderer/Common
    ../SnakeCPP/Base/Controllers/Renderer/MockRenderer
    ../SnakeCPP/Base/Controllers/Renderer/WindowRenderer
    ../SnakeCPP/Base/Controllers/GameController
    ../SnakeCPP/GameObjects/Common
    ../SnakeCPP/GameObjects/Fruit
    ../SnakeCPP/GameObjects/Snake
)

# Add library for the main project
add_library(SnakeCPP
    ../SnakeCPP/Base/Controllers/GameController/GameController.cpp
    ../SnakeCPP/Base/Controllers/Renderer/WindowRenderer/WindowRenderer.cpp
    ../SnakeCPP/GameObjects/Snake/Snake.cpp
    ../SnakeCPP/GameObjects/Fruit/Fruit.cpp
    ../SnakeCPP/Base/Window/Window.cpp
)

# Link test executable with Google Test and main project
target_link_libraries(${PROJECT_NAME} gtest SnakeCPP pthread)

# Add test target for running tests
add_test(NAME AllTests COMMAND tests)