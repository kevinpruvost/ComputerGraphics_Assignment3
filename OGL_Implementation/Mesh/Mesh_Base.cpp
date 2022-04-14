/*****************************************************************//**
 * \file   Mesh_Base.cpp
 * \brief  Mesh_Base Source Code
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 03 2022
 *********************************************************************/
#include "Mesh_Base.hpp"

// Project includes
#include "OGL_Implementation\DebugInfo\Log.hpp"

Mesh_Base::Mesh_Base()
{
	LOG_PRINT(Log::LogMainFileName, "Constructed\n");
}

Mesh_Base::~Mesh_Base()
{
	LOG_PRINT(Log::LogMainFileName, "Destroyed\n");
}

GLuint Mesh_Base::GetVerticesVAO() const
{
	return __verticesVAO;
}

GLuint Mesh_Base::GetFacesVAO() const
{
	return __facesVAO;
}

GLuint Mesh_Base::GetVerticesVBO() const
{
	return __verticesVBO;
}

GLuint Mesh_Base::GetFacesVBO() const
{
	return __facesVBO;
}

GLuint Mesh_Base::GetVerticesCount() const
{
	return __verticesNVert;
}

GLuint Mesh_Base::GetFacesVerticesCount() const
{
	return __facesNVert;
}
