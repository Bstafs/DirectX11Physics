#include "ParticleModel.h"
ParticleModel::ParticleModel()
{
	m_weight = 10.0f;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(const float deltaTime)
{
	//Gravity();
	MoveConstantVelocity(deltaTime);
	MoveConstantAcceleration(deltaTime);
}

void ParticleModel::MoveConstantVelocity(const float deltaTime)
{
	m_velocity = m_velocity + m_acceleration * deltaTime;
}

void ParticleModel::MoveConstantAcceleration(const float deltaTime)
{
	m_acceleration = m_netForce / m_mass;
}

void ParticleModel::Gravity()
{
	m_weight = m_mass * m_gravity;
	m_netForce.y -= m_weight * m_weightLimit;
}