#include "RigidBody.h"

RigidBody::RigidBody()
{

}

RigidBody::~RigidBody()
{

}

void RigidBody::Update(float deltaTime)
{
	CalculateTorque();
	CalculateInertiaTensor(1.0f, 1.0f, 1.0f);
	CalculateAngularAcceleration();
	CalculateAngularVelocity(deltaTime);
	DampingForce(deltaTime);
	CalculateAngularOrientation();
}

void RigidBody::CalculateTorque()
{
	XMStoreFloat3(&m_torque, XMVector3Cross(m_position, m_force));
}

void RigidBody::CalculateInertiaTensor(float dx, float dy, float dz)
{
	m_inertiaTensor = XMFLOAT3X3();
	m_inertiaTensor._11 = (1 / 12) * 1.0 * (dy * dy + dz * dz); // change 1.0 to mass // _11 _12 _13
 	m_inertiaTensor._22 = (1 / 12) * 1.0 * (dx * dx + dz * dz);                       // _21 _22 _23
 	m_inertiaTensor._33 = (1 / 12) * 1.0 * (dx * dx + dy * dy);                       // _31 _32 _33
}

void RigidBody::CalculateAngularAcceleration()
{
	XMMATRIX inverted = XMMatrixInverse(nullptr, XMLoadFloat3x3(&m_inertiaTensor));
	XMStoreFloat3(&m_angularAcceleration, XMVector3Transform(XMLoadFloat3(&m_torque), inverted));
}

void RigidBody::CalculateAngularVelocity(float deltaTime)
{
	m_newVelocity.x = m_oldVelocity.x + m_angularAcceleration.x * deltaTime;
	m_newVelocity.y = m_oldVelocity.y + m_angularAcceleration.y * deltaTime;
	m_newVelocity.z = m_oldVelocity.z + m_angularAcceleration.z * deltaTime;

}

void RigidBody::DampingForce(float deltaTime)
{

}

void RigidBody::CalculateAngularOrientation()
{
	
}