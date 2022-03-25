#include "ParticleModel.h"
ParticleModel::ParticleModel()
{
	m_weight = 10.0f;
	m_gravity = 9.81f;
	m_useLaminar = true;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(const float deltaTime)
{
	Gravity();
	MoveConstantAcceleration();
	MoveConstantVelocity(deltaTime);
	DragForce();
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
	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
	m_position.z += m_velocity.z * deltaTime;
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

void ParticleModel::DragForce()
{
	if (m_useLaminar == true)
	{
		DragLaminar();
	}
	else
	{
		DragTurbulent();
	}
}

void ParticleModel::DragLaminar()
{
	m_netForce.x -= m_velocity.x * m_drag.x;
	m_netForce.y -= m_velocity.y * m_drag.y;
	m_netForce.z -= m_velocity.z * m_drag.z;
}

void ParticleModel::DragTurbulent()
{
	float velocityMagnitude = m_velocity.Magnitude();
	Vector3 unitVelocity = m_velocity.Normalize();

	float dragMagnitudeX = m_drag.x * velocityMagnitude * velocityMagnitude;
	float dragMagnitudeY = m_drag.y * velocityMagnitude * velocityMagnitude;
	float dragMagnitudeZ = m_drag.z * velocityMagnitude * velocityMagnitude;

	m_drag.x = -dragMagnitudeX * unitVelocity.x;
	m_drag.y = -dragMagnitudeY * unitVelocity.y;
	m_drag.z = -dragMagnitudeZ * unitVelocity.z;
}