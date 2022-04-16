/*****************************************************************//**
 * \file   ParticleSystem_Spirals.cpp
 * \brief  ParticleSystem Spirals source code
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 15 2022
 *********************************************************************/
#include "ParticleSystem_Spirals.hpp"

// Project includes
#include "OGL_Implementation\Window.hpp"

ParticleSystem_Spiral::ParticleSystem_Spiral(const Shader & shaderPoint_, const Shader & shaderWireframe_, const Shader & shaderPS_)
    : ParticleSystem_Base(shaderPoint_, shaderWireframe_, shaderPS_, 5.0f, 10.0f, 50)
    , speed{ 1.0f }
    , spiralType{ SpiralType::ArchimedesSpiral }
    , alpha{ 1.0f }
    , beta{ 1.0f }
{
    __particles.reserve(maxParticles);
}

ParticleSystem_Spiral::~ParticleSystem_Spiral()
{
}

void ParticleSystem_Spiral::UpdateParticle(Particle_Base * particle_)
{
    Particle_Spiral & particle = *particle_->Cast<Particle_Spiral>();

    const float deltaTime = Window::Get()->deltaTime();

    particle.theta += deltaTime * speed;
    
    const std::array<std::function<void()>, 3> lambdasUpdatePosition{
        [&]() { // Archimedes Spiral
            particle.pos = CalculateArchimedesSpiral(particle.theta, alpha, beta);
        },
        [&]() { // Fermat Spiral
            particle.pos = CalculateFermatSpiral(particle.theta, alpha);
        },
        [&]() { // Logarithmic Spiral
            particle.pos = CalculateLogSpiral(particle.theta, alpha, beta);
        }
    };
    lambdasUpdatePosition[spiralType]();
}

Particle_Base * ParticleSystem_Spiral::SpawnParticle()
{
    return new Particle_Spiral(lifeSpan, pos, scale, {
        (100.0f + rand() % 255) / 255.0f, // R
        (100.0f + rand() % 255) / 255.0f, // G
        (100.0f + rand() % 255) / 255.0f, // B
        1.0f  // A
    });
}

Particle_Base::ParticlePropertiesStyle ParticleSystem_Spiral::GetParticlePropertiesStyle() const
{
    return Particle_Base::ParticlePropertiesStyle::Color;
}