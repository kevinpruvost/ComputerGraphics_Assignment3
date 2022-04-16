/*****************************************************************//**
 * \file   ParticleSystem.cpp
 * \brief  ParticleSystem source code
 * 
 * \author Kevin Pruvost (pruvostkevin0@gmail.com)
 * \date   April, 14 2022
 *********************************************************************/
#include "ParticleSystem.hpp"

// Project includes
#include "OGL_Implementation\Window.hpp"

ParticleSystem_Base::ParticleSystem_Base(const Shader & shaderPoint_, const Shader & shaderWireframe_, const Shader & shaderPS_,
    const float lifeSpan_, const float frequency_, const unsigned int maxParticles_)
    : pos{ 0.0f }
    , quat{}
    , scale(1.0f)
    , lifeSpan{ lifeSpan_ }
    , frequency{ frequency_ }
    , maxParticles{ maxParticles_ }
    , __turnedOn{ false }
    , __particleIte{ __particles.end() }
    , shaderPoint{ shaderPoint_ }
    , shaderWireframe{ shaderWireframe_ }
    , shaderParticleSystem{ shaderPS_ }
    , displayMode{ RenderingMode::FacesMode }
{
}

ParticleSystem_Base::~ParticleSystem_Base()
{
}

void ParticleSystem_Base::Update()
{
    // Spawn process
    const float deltaTime = Window::Get()->deltaTime();

    int i = 0;
    for (__particleIte = __particles.begin(); __particleIte != __particles.end();)
    {
        if (__particleIte->get()->GetLifeSpan() <= FLT_EPSILON)
        {
            RemoveParticle();
            continue;
        }
        std::unique_ptr<Particle_Base> & particle = *__particleIte;
        particle->UpdateLifeSpan(deltaTime);
        UpdateParticle(&(*particle));
        ++__particleIte;
    }

    __deltaTimeCounter -= deltaTime;
    if (__deltaTimeCounter <= 0.000f)
    {
        ResetCounter();
        if (__particles.size() < maxParticles)
        {
            __particles.emplace_back(SpawnParticle());
        }
    }
}

inline void ParticleSystem_Base::RemoveParticle()
{
    __particleIte = __particles.erase(__particleIte);
}

glm::mat4 ParticleSystem_Base::GetModelMatrix(bool ignoreRotation, bool ignoreScale) const
{
    // Transformation Matrix
    glm::mat4 mat = {
        {1.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f},
        {pos.x, pos.y, pos.z, 1.0f}
    };
    // Rotation Matrix
    if (!ignoreRotation)
        mat *= glm::toMat4(quat);
    // Scaling Matrix
    if (!ignoreScale)
        mat = glm::scale(mat, scale);

    if (HasParent())
        mat = this->GetParent()->GetModelMatrix(false, true) * mat;
    return mat;
}

glm::vec3 ParticleSystem_Base::GetLocalPosition() const
{
    return pos;
}

glm::vec3 ParticleSystem_Base::GetWorldPosition() const
{
    if (HasParent())
    {
        const glm::mat4 modelMatrix = GetModelMatrix();
        const glm::vec3 position{ modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2] };
        return position;
    }
    return pos;
}

void ParticleSystem_Base::Start()
{
    __turnedOn = true;
    ResetCounter();
}

void ParticleSystem_Base::Stop()
{
    __turnedOn = false;
}

const std::vector<std::unique_ptr<Particle_Base>> & ParticleSystem_Base::GetParticles() const
{
    return __particles;
}

const ParticleSystem_Base * ParticleSystem_Base::ToParticleSystemBase() const
{
    return dynamic_cast<const ParticleSystem_Base *>(this);
}

ParticleSystem_Base * ParticleSystem_Base::ToParticleSystemBase()
{
    return dynamic_cast<ParticleSystem_Base *>(this);
}

inline void ParticleSystem_Base::ResetCounter()
{
    __deltaTimeCounter = 1.0f / frequency;
}