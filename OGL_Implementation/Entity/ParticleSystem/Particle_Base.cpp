/*****************************************************************//**
 * \file   Particle_Base.cpp
 * \brief  Particle Base source code
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 15 2022
 *********************************************************************/
#include "Particle_Base.hpp"

Particle_Base::Particle_Base(const float lifeSpan, const glm::vec3 & pos_, const glm::vec3 & scale_)
    : __lifeSpan{ lifeSpan }
    , pos{ pos_ }
    , scale{ scale_ }
{
}

Particle_Base::~Particle_Base()
{
}

glm::mat4 Particle_Base::GetModelMatrix(bool ignoreRotation, bool ignoreScale) const
{
    // Transformation Matrix
    glm::mat4 mat = {
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {pos.x, pos.y, pos.z, 1.0f}
    };
    // Scaling Matrix
    if (!ignoreScale)
        mat = glm::scale(mat, scale);
    return mat;
}

glm::vec3 Particle_Base::GetLocalPosition() const
{
    return pos;
}

void Particle_Base::UpdateLifeSpan(const float deltaTime)
{
    __lifeSpan -= deltaTime;
}

float Particle_Base::GetLifeSpan() const
{
    return __lifeSpan;
}

const Particle_Base * Particle_Base::ToBase() const
{
    return dynamic_cast<const Particle_Base *>(this);
}

Particle_Base * Particle_Base::ToBase()
{
    return dynamic_cast<Particle_Base *>(this);
}
