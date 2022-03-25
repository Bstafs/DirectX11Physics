#include "ParticleModel.h"
ParticleModel::ParticleModel()
{
	m_weight = 10.0f;
	m_gravity = 9.81f;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(const float deltaTime)
{
	Gravity();
	MoveConstantAcceleration();
	MoveConstantVelocity(deltaTime);
	
	UpdatePosition(deltaTime);
	
	m_netForce = Vector3(0, 0, 0);
	m_acceleration = Vector3(0, 0, 0);
}

void ParticleModel::MoveConstantVelocity(const float deltaTime)
{
	m_velocity = m_velocity + m_acceleration * deltaTime;
}

void ParticleModel::MoveConstantAcceleration()
{
	m_acceleration = m_netForce / m_mass;
}

void ParticleModel::UpdatePosition(const float deltaTime)
{
	Vector3 m_position = m_transform->GetPosition();
	m_position.x += m_velocity.x * deltaTime + 0.5 * m_acceleration.x * deltaTime * deltaTime;
	m_position.y += m_velocity.y * deltaTime + 0.5 * m_acceleration.y * deltaTime * deltaTime;
	m_position.z += m_velocity.z * deltaTime + 0.5 * m_acceleration.z * deltaTime * deltaTime;
	m_transform->SetPosition(m_position.x, m_position.y, m_position.z);
}

void ParticleModel::Gravity()
{
	if (m_transform->GetPosition().y < 0.5f)
	{
		m_hasGravity = false;
	}
	else
	{
		m_hasGravity = true;
	}

	if (m_hasGravity == true)
	{
		m_weight = m_mass * m_gravity;
		m_netForce.y -= m_weight;
	}
	else
	{
		return;
	}
}

