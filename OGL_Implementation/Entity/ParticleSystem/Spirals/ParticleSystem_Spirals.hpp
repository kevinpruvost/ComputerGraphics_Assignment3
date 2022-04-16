/*****************************************************************//**
 * \file   ParticleSystem_Spirals.hpp
 * \brief  Particle System Spirals class
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 15 2022
 *********************************************************************/
#pragma once

// Project includes
#include "Particle_Spirals.hpp"

#include "../ParticleSystem_Base.hpp"
#include "../ParticleSystemGeometry.hpp"

class ParticleSystem_Spiral : public ParticleSystem_Base
{
public:
    enum SpiralType
    {
        ArchimedesSpiral  = 0,
        FermatSpiral      = 1,
        LogarithmicSpiral = 2
    };

public:
    ParticleSystem_Spiral(const Shader & shaderPoint_, const Shader & shaderWireframe_, const Shader & shaderPS_);
    ~ParticleSystem_Spiral();

    void UpdateParticle(Particle_Base * particle);
    Particle_Base * SpawnParticle();

    Particle_Base::ParticlePropertiesStyle GetParticlePropertiesStyle() const;

private:

public:
    /// @brief Speed
    float speed;
    /// @brief Spiral Type
    SpiralType spiralType;

    float alpha, beta;

private:
};
