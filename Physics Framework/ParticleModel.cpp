#include "ParticleModel.h"
ParticleModel::ParticleModel(Vector3 velocity, Vector3 position)
{
	m_velocity = velocity;
	m_position = position;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float t)
{
	moveConstantVelocity(t);
}

void ParticleModel::moveConstantVelocity(const float deltaTime)
{
	m_displacement = m_velocity * deltaTime;
	m_position = m_displacement + m_velocity * deltaTime;
}

Vector3 ParticleModel::GetVelocity()
{
	return m_velocity;
}

void ParticleModel::SetVelocity(Vector3 velocity)
{
	m_velocity = velocity;
}

Vector3 ParticleModel::GetPosition()
{
	return m_position;
}

void ParticleModel::SetPosition(Vector3 position)
{
	m_position = position;
}