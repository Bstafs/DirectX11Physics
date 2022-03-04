#include "RigidBody.h"

RigidBody::RigidBody()
{
	CalculateTorque();
	CalculateInertiaTensor(1.0f, 1.0f, 1.0f);
	CalculateAngularAcceleration();
}

RigidBody::~RigidBody()
{

}

XMFLOAT3 RigidBody::CalculateTorque()
{
	m_torque = m_position.CrossProduct(m_force);  // Fix Calculate Torque
	return m_torque;
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
	XMStoreFloat3(&m_angularAcceleration, XMVector3Transform(XMLoadFloat3(&m_torque), inverted)
}