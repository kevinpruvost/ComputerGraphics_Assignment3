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

// GLM includes
#include <glm/gtx/string_cast.hpp>

ParticleSystem_Spiral::ParticleSystem_Spiral(const Shader & shaderPoint_, const Shader & shaderWireframe_, const Shader & shaderPS_)
    : ParticleSystem_Base(shaderPoint_, shaderWireframe_, shaderPS_, 5.0f, 10.0f, 50)
    , speed{ 1.0f }
    , spiralType{ SpiralType::ArchimedesSpiral }
    , alpha{ 1.0f }
    , beta{ 1.0f }
    , __theta{ 0.0f }
{
    __particles.reserve(maxParticles);
}

ParticleSystem_Spiral::~ParticleSystem_Spiral()
{
}

void ParticleSystem_Spiral::OnUpdate()
{
}

void ParticleSystem_Spiral::UpdateParticle(Particle_Base * particle_)
{
    Particle_Spiral & particle = *particle_->Cast<Particle_Spiral>();

    if (glm::length(particle.acceleration) > FLT_EPSILON)
        particle.speed += _deltaTime * particle.acceleration;
    particle.pos += particle.speed * _deltaTime;
}

std::vector<Particle_Base *> ParticleSystem_Spiral::SpawnParticle()
{
    std::vector<Particle_Base *> newParticles;    

    const std::array<std::function<void()>, 3> lambdasUpdatePosition{
        [&]() { // Archimedes Spiral
            auto & particle = newParticles.emplace_back(new Particle_Spiral(lifeSpan, pos, scale, {
                (100.0f + rand() % 255) / 255.0f, // R
                (100.0f + rand() % 255) / 255.0f, // G
                (100.0f + rand() % 255) / 255.0f, // B
                1.0f  // A
            }));

            glm::vec3 speedP = glm::normalize(CalculateArchimedesSpiral(__theta, alpha, beta));
            particle->SetMovement(speedP * speed * 0.1f, glm::vec3(0.0f));
    },
        [&]() { // Fermat Spiral
            glm::vec3 speedP = glm::normalize(CalculateFermatSpiral(__theta, alpha));
            auto & particle1 = newParticles.emplace_back(new Particle_Spiral(lifeSpan, pos, scale, {
                (100.0f + rand() % 255) / 255.0f, // R
                (100.0f + rand() % 255) / 255.0f, // G
                (100.0f + rand() % 255) / 255.0f, // B
                1.0f  // A
            }));
            particle1->SetMovement(speedP * speed * 0.1f, glm::vec3(0.0f));
            auto & particle2 = newParticles.emplace_back(new Particle_Spiral(lifeSpan, pos, scale, {
                (100.0f + rand() % 255) / 255.0f, // R
                (100.0f + rand() % 255) / 255.0f, // G
                (100.0f + rand() % 255) / 255.0f, // B
                1.0f  // A
            }));
            particle2->SetMovement(-speedP * speed * 0.1f, glm::vec3(0.0f));
    },
        [&]() { // Logarithmic Spiral
            auto & particle = newParticles.emplace_back(new Particle_Spiral(lifeSpan, pos, scale, {
                (100.0f + rand() % 255) / 255.0f, // R
                (100.0f + rand() % 255) / 255.0f, // G
                (100.0f + rand() % 255) / 255.0f, // B
                1.0f  // A
            }));

            glm::vec3 speedP = CalculateLogSpiral(__theta, alpha, beta);
            particle->SetMovement(speedP * speed * 0.1f, glm::vec3(0.0f));
        }
    };
    lambdasUpdatePosition[spiralType]();
    __theta += 1.0f / frequency;
    return newParticles;
}

void ParticleSystem_Spiral::OnStart()
{
}

void ParticleSystem_Spiral::OnStop()
{
}

void ParticleSystem_Spiral::OnReset()
{
    __theta = 0.0f;
}

Particle_Base::ParticlePropertiesStyle ParticleSystem_Spiral::GetParticlePropertiesStyle() const
{
    return Particle_Base::ParticlePropertiesStyle::Color;
}