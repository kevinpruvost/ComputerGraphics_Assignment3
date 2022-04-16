/*****************************************************************//**
 * \file   Particle_Base.hpp
 * \brief  Particle Base class
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 15 2022
 *********************************************************************/
#pragma once

// Project includes
#include "../Entity.hpp"

// GLM includes
#include <GLM\glm.hpp>

class Particle_Base;

/// @brief Concept checking if the type is based on particle class
template<class T>
concept Particle_Based = std::is_base_of_v<Particle_Base, T>;

class Particle_Base : public Entity_Skeleton
{
public:
    Particle_Base(const float lifeSpan, const glm::vec3 & pos_, const glm::vec3 & scale_);
    ~Particle_Base();

    virtual glm::mat4 GetModelMatrix(bool ignoreRotation = false, bool ignoreScale = false) const;
    virtual glm::vec3 GetLocalPosition() const;

    void UpdateLifeSpan(const float deltaTime);
    float GetLifeSpan() const;

    const Particle_Base * ToBase() const;
    Particle_Base * ToBase();

    template<Particle_Based PType>
    const PType * Cast() const;
    template<Particle_Based PType>
    PType * Cast();

public:
    glm::vec3 pos;
    glm::vec3 scale;

public:
    // Conditional Properties
    glm::vec4 color;

    enum class ParticlePropertiesStyle : unsigned int
    {
        Color = 1 << 0,
    };

private:
    float __lifeSpan;
};

#include "Particle_Base.inl"
