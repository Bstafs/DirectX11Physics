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
	CheckCollisions();

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
	m_weight = m_mass * m_gravity;
	m_netForce.y -= m_weight;

	//if (m_transform->GetPosition().y < 0.5f)
	//{
	//	m_hasGravity = false;
	//}
	//else
	//{
	//	m_hasGravity = true;
	//}

	//if (m_hasGravity == true)
	//{
	//	m_weight = m_mass * m_gravity;
	//	m_netForce.y -= m_weight;
	//}
	//else
	//{
	//	return;
	//}
}

void ParticleModel::DragForce()
{
	if (m_useLaminar == true)
	{
		DragLaminarFlow();
	}
	else
	{
		DragTurbulentFlow();
	}
}

void ParticleModel::DragLaminarFlow()
{
	m_netForce.x -= m_velocity.x * m_drag.x;
	m_netForce.y -= m_velocity.y * m_drag.y;
	m_netForce.z -= m_velocity.z * m_drag.z;
}

void ParticleModel::DragTurbulentFlow()
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

void ParticleModel::CheckCollisions()
{
	Vector3 objectPosition = m_transform->GetPosition();

	if (objectPosition.x < -9.5f)
	{
		objectPosition.x = -9.5f;
	}
	else if (objectPosition.x > 9.5)
	{
		objectPosition.x = 9.5f;
	}

	if (objectPosition.y < 0)
	{
		m_velocity.y = 0.0f; // Counting for Gravity

		objectPosition.y = 0.0f;
	}
	else if (objectPosition.y > 9.5f)
	{
		m_velocity.y = 0.0f; // Counting for Gravity

		objectPosition.y = 9.5f;
	}

	if (objectPosition.z < -4.5)
	{
		objectPosition.z = -4.5;
	}
	else if (objectPosition.z > 19.5f)
	{
		objectPosition.z = 19.5f;
	}

	m_transform->SetPosition(objectPosition);

}

bool ParticleModel::CheckSphereColision(Vector3 position, float radius)
{
	if ((m_transform->GetPosition().x - position.x) * (m_transform->GetPosition().x - position.x) + (m_transform->GetPosition().y - position.y) * (m_transform->GetPosition().y - position.y) + (m_transform->GetPosition().z - position.z) * (m_transform->GetPosition().z - position.z) <= radius * radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}