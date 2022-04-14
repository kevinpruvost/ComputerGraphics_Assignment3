/*****************************************************************//**
 * \file   Entity_Skeleton.cpp
 * \brief  Entity Skeleton source code
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 08 2022
 *********************************************************************/
#include "Entity_Skeleton.hpp"

// Project includes
#include "OGL_Implementation\DebugInfo\Log.hpp"

Entity_Skeleton::Entity_Skeleton()
    : __parent{ nullptr }
{
}

Entity_Skeleton::~Entity_Skeleton()
{
    RemoveParent();
    RemoveChildren();
}

bool Entity_Skeleton::HasChildren() const
{
    return !__children.empty();
}

size_t Entity_Skeleton::ChildrenCount() const
{
    return __children.size();
}

bool Entity_Skeleton::HasParent() const
{
    return __parent != nullptr;
}

void Entity_Skeleton::RemoveParent()
{
    if (__parent)
    {
        __parent->RemoveChild(this);
        __parent = nullptr;
    }
}

void Entity_Skeleton::RemoveChildren()
{
    if (!__children.empty())
    {
        for (auto * child : __children)
        {
            child->RemoveParent();
        }
        __children.clear();
    }
}

const std::vector<Entity_Skeleton *> & Entity_Skeleton::GetChildren() const
{
    return __children;
}
