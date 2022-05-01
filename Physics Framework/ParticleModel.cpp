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
<<<<<<< HEAD
<<<<<<< HEAD
	//CheckFloorCollisions();
	Gravity();
	Friction();
=======
>>>>>>> parent of e14c98f (Week 10 - Finished Forces)
=======
>>>>>>> parent of e14c98f (Week 10 - Finished Forces)
	DragForce();
	//Gravity();
	MoveConstantAcceleration();
	MoveConstantVelocity(deltaTime);
	UpdatePosition(deltaTime);
<<<<<<< HEAD
	CheckLevel();
=======
	CheckFloorCollisions();
>>>>>>> parent of 16b1661 (Fixed Stuff)

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
<<<<<<< HEAD
	if (m_toggleGravity == true)
	{
		m_weight = m_mass * m_gravity;
<<<<<<< HEAD
	    m_netForce.y -= m_weight;
=======
		m_netForce.y -= m_weight;
>>>>>>> parent of 16b1661 (Fixed Stuff)
	}
	else
	{
		return;
	}
=======
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
<<<<<<< HEAD
>>>>>>> parent of e14c98f (Week 10 - Finished Forces)
=======
>>>>>>> parent of e14c98f (Week 10 - Finished Forces)
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
	float dragFactor = 0.8f;

	m_drag.x = (dragFactor * m_velocity.x) * -1.0f;
	m_drag.y = (dragFactor * m_velocity.y) * -1.0f;
	m_drag.z = (dragFactor * m_velocity.z) * -1.0f;

	m_netForce += m_drag;
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

<<<<<<< HEAD
=======
void ParticleModel::CheckFloorCollisions()
{
	Vector3 objectPosition = m_transform->GetPosition();

	if (objectPosition.y < 0.0)
	{
		m_velocity.y = 0.5f; // Counting for Gravity

		objectPosition.y = 0.5f;
	}
	else if (objectPosition.y > 20.0f)
	{
		m_velocity.y = 0.0f; // Counting for Gravity

		objectPosition.y = 20.0f;
	}

	m_transform->SetPosition(objectPosition);
}

>>>>>>> parent of e14c98f (Week 10 - Finished Forces)
bool ParticleModel::CheckSphereColision(Vector3 position, float radius)
{
	return ((m_transform->GetPosition().x - position.x) * (m_transform->GetPosition().x - position.x) + 
		(m_transform->GetPosition().y - position.y) * (m_transform->GetPosition().y - position.y) + 
		(m_transform->GetPosition().z - position.z) * (m_transform->GetPosition().z - position.z) <= m_boundSphereRadius * radius);
}

bool ParticleModel::CheckAABBCollision(Vector3 position, float radius)
{
	float radiusSq = radius * radius;
	float distanceSq = (position.x * position.x) + (position.y * position.y) + (position.z * position.z);
	float distance = sqrt(distanceSq); 

	return false;
}

void ParticleModel::CheckLevel()
{
	Vector3 position = m_transform->GetPosition();

	if (position.y < 0.0f)
	{
<<<<<<< HEAD
		m_transform->SetPosition(position.x, 5.0f, position.z);
		m_velocity.y = 0.0f;
=======
		
	}

	if (dMin <= radiusSq)
	{
		return true;
>>>>>>> parent of 16b1661 (Fixed Stuff)
	}
}