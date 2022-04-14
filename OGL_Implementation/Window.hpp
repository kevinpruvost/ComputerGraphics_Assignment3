/*****************************************************************//**
 * \file   Window.hpp
 * \brief  Managing OpenGL Window
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   March, 26 2022
 *********************************************************************/
#pragma once

// Project includes
#include "Input.hpp"

// C++ includes
#include <vector>

/**
 * @brief Manages everything about the OpenGL window.
*/
class Window : public Input
{
public:
    Window();
    ~Window();

    /**
    * @brief Initializes OpenGL window.
    * @param windowName
    * @return true if initialization has succeeded, false otherwise
    */
    bool Init(const char * windowName = "Window", const char * iconPath = nullptr);
    /**
     * @brief Launches the window loop and the code contained in the lambda function.
     * @param lambda
     * @return lambda's return value
    */
    bool Loop(const std::function<bool()> & lambda);
    /**
     * @brief Calculates period between the current frame & the last frame
     * in seconds
     * @return Delta Time from last frame
    */
    float deltaTime() const;
    /**
     * @brief Returns Window current Width
     * @return window width 
    */
    int windowWidth() const;
    /**
     * @brief Returns Window current Height
     * @return window height
    */
    int windowHeight() const;
    /**
     * @brief window dimensions have changed
     * @return has changed
    */
    bool windowDimensionsHasChanged() const;
    /**
     * @brief Returns if window is focused or not
     * @return window focused 
    */
    bool GetWindowFocused() const;

public:
    /**
     * @brief GLFW Window
    */
    GLFWwindow * window;
private:
    GLboolean __initialized;
    float __deltaTime;
};
