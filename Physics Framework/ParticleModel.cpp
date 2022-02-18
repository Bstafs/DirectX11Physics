#include "ParticleModel.h"
ParticleModel::ParticleModel(vector3d velocity, vector3d position)
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

}

vector3d ParticleModel::GetVelocity()
{
	return m_velocity;
}

void ParticleModel::SetVelocity(vector3d velocity)
{
	m_velocity = velocity;
}

vector3d ParticleModel::GetPosition()
{
	return m_position;
}

void ParticleModel::SetPosition(vector3d position)
{
	m_position = position;
}