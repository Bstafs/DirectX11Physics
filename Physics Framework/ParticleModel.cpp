#include "ParticleModel.h"
ParticleModel::ParticleModel()
{
	m_weight = 10.0f;
	m_gravity = 9.81f;
	m_useLaminar = false;
}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(const float deltaTime)
{
	DragForce();
	//Gravity();
	MoveConstantAcceleration();
	MoveConstantVelocity(deltaTime);
	
	UpdatePosition(deltaTime);
	CheckFloorCollisions();

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
	m_position.z += m_velocity.z * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
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

}

void ParticleModel::DragTurbulentFlow()
{
	if (m_velocity.Magnitude() < 0.1f) return;
	float velocityMagnitude = m_velocity.Magnitude();
	Vector3 unitVelocity = m_velocity.Normalize();

	float fluidDensity = 1.225f;
	float referenceArea = 1.0f;    
	float dragCoefficient = 1.05f; // cube drag coefficient 

	// 0.5 * fluid density * drag coefficient * reference area * velocity * velocity
   	m_drag.x = 0.5 * fluidDensity * dragCoefficient * referenceArea * velocityMagnitude * velocityMagnitude;
	m_drag.y = 0.5 * fluidDensity * dragCoefficient * referenceArea * velocityMagnitude * velocityMagnitude;	
	m_drag.z = 0.5 * fluidDensity * dragCoefficient * referenceArea * velocityMagnitude * velocityMagnitude;

	m_drag = (unitVelocity * m_drag.x) * -1.0f;
	m_drag = (unitVelocity * m_drag.y) * -1.0f;
	m_drag = (unitVelocity * m_drag.z) * -1.0f;


	m_netForce += m_drag;
}

void ParticleModel::CheckFloorCollisions()
{
	Vector3 objectPosition = m_transform->GetPosition();

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

	m_transform->SetPosition(objectPosition);
}

bool ParticleModel::CheckSphereColision(Vector3 position, float radius)
{
	return ((m_transform->GetPosition().x - position.x) * (m_transform->GetPosition().x - position.x) + 
		(m_transform->GetPosition().y - position.y) * (m_transform->GetPosition().y - position.y) + 
		(m_transform->GetPosition().z - position.z) * (m_transform->GetPosition().z - position.z) <= m_boundSphereRadius * radius);
}

bool ParticleModel::CheckAABBCollision()
{
	float radius = GetCollisionRadius();
	float radiusSq = radius * radius;

	int dMin = 0;

}