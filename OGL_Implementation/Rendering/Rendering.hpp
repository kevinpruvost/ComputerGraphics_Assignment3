/*****************************************************************//**
 * \file   Rendering.hpp
 * \brief  Rendering class
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 04 2022
 *********************************************************************/
#pragma once

// Project includes
#include "OGL_Implementation\Entity\Entity.hpp"
#include "OGL_Implementation\Text\Text.hpp"
#include "OGL_Implementation\Light\Light.hpp"

/**
 * @brief Static class containing rendering utilities
*/
class Rendering
{
public:
    Rendering();
    ~Rendering();
public:
    GLuint GetTextVAO();
    GLuint GetTextVBO();

private:
    GLuint __textVAO, __textVBO;

public:
    /**
     * @brief To call to initialize Rendering
    */
    static void Init();
    static void Refresh();

    // Entities
    static void DrawFaces(Entity & entity);
    static void DrawWireframe(Entity & entity);
    static void DrawVertices(Entity & entity);

    static void RotateWireframeColor();

    // Text
    static void DrawText(Text2D & text);
    static void DrawText(Text3D & text);
};
