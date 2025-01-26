/**
 * Snake game written in C++ using winAPI.
 * Copyright (C) 2025  Mateusz Zynek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Window.hpp
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../GameObjects/Snake/Snake.hpp"
#include "../../GameObjects/Fruit/Fruit.hpp"
#include <string>
#include <unordered_map>
#include <memory>
#include <atomic>
#include <thread>

/**
 * @class Window
 * @brief Represents the game window and handles its rendering and logic.
 */
class Window
{
private:
    HWND m_hwnd;                                    // Handle to the game window.
    HDC m_memoryDC;                                 // Memory device context for double buffering.
    HBITMAP m_memoryBitmap;                         // Bitmap for double buffering.
    WPARAM m_lastKey;                               // Stores the last pressed key.
    bool m_isInputPending;                          // Indicates if input is pending to be processed.
    std::string m_title;                            // Title of the window.
    std::atomic<bool> m_isRunning;                  // Indicates if the game is running.
    std::thread m_updateThread;                     //  Thread for animations and game logic updates.
    std::unique_ptr<Snake> m_snake;                 // The snake object.
    std::unique_ptr<Fruit> m_fruit;                 // The fruit object.
    std::unordered_map<COLORREF, HBRUSH> m_brushes; // Caches brushes for different colors.

public:
    /**
     * @brief Constructs the game window with the specified title.
     *
     * @param title The title of the window.
     */
    Window(const std::string &title);

    /**
     * @brief Destroys the game window and releases resources.
     */
    ~Window();

    /**
     * @brief Creates the game window.
     *
     * @param hInstance The handle to the application instance.
     * @return True if the window was successfully created, false otherwise.
     */
    bool create(const HINSTANCE &hInstance);

    /**
     * @brief Displays the game window.
     *
     * @param nCmdShow The show command for the window.
     */
    void show(const int &nCmdShow);

    /**
     * @brief Runs the main game loop.
     */
    void run();

private:
    /**
     * @brief Updates the game state in a separate thread.
     */
    void update();

    /**
     * @brief Retrieves or creates a brush of the specified color.
     *
     * @param color The color of the brush.
     * @return The handle to the brush.
     */
    HBRUSH getBrush(const COLORREF &color);

    /**
     * @brief Handles specific window messages.
     *
     * @param uMsg The message ID.
     * @param wParam Additional message information.
     * @param lParam Additional message information.
     * @return The result of message processing.
     */
    LRESULT handleMsg(UINT uMsg, WPARAM wParam, LPARAM lParam);

    /**
     * @brief Window procedure: Delegates messages to the appropriate handler.
     *
     * @param hwnd Handle to the window.
     * @param uMsg The message ID.
     * @param wParam Additional message information.
     * @param lParam Additional message information.
     * @return The result of message processing.
     */
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

#endif