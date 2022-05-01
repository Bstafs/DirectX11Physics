#include "RigidBody.h"

RigidBody::RigidBody()
{
	m_orientation = Quaternion();
	m_angularDamping = 0.9f;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Update(const float deltaTime)
{
	// Calculate Torque
	CalculateTorque();

	//Calculate Inertia Tensor
	CalculateInertiaTensor(1.0f,1.0f,1.0f);

	//Calculate Angular Acceleration
	CalculateAngularAcceleration();

	//Calculate Angular Velocity
	CalculateAngularVelocity(deltaTime);

	//Calculate Drag
	CalculateDrag(deltaTime);

	//Calculate Angular Orientation
	CalculateAngularOrientation(deltaTime);
}

Vector3 RigidBody::CalculateTorque()
{
	m_torque = Vector3(0, 0, 0); //m_position.CrossProduct(m_netForce);
	return m_torque;
}

XMFLOAT3X3 RigidBody::CalculateInertiaTensor(float dx, float dy, float dz)
{
	m_inertiaTensor = XMFLOAT3X3();
	m_inertiaTensor._11 = (1 / 12) * m_mass * (dy * dy + dz * dz); // change 1.0 to mass // _11 _12 _13
 	m_inertiaTensor._22 = (1 / 12) * m_mass * (dx * dx + dz * dz);                       // _21 _22 _23
 	m_inertiaTensor._33 = (1 / 12) * m_mass * (dx * dx + dy * dy);                       // _31 _32 _33
	return m_inertiaTensor;
}

XMFLOAT3 RigidBody::CalculateAngularAcceleration()
{

	XMMATRIX inverted = XMMatrixInverse(nullptr, XMLoadFloat3x3(&m_inertiaTensor));
	XMFLOAT3 torque = m_torque.Vector3ToXMFLOAT3();
	XMStoreFloat3(&m_angularAcceleration, XMVector3Transform(XMLoadFloat3(&torque), inverted));
	return m_angularAcceleration;
}

Vector3 RigidBody::CalculateAngularVelocity(const float deltaTime)
{
	m_angularVelocity.x = m_angularVelocity.x + m_angularAcceleration.x * deltaTime;
	m_angularVelocity.y = m_angularVelocity.y + m_angularAcceleration.y * deltaTime;
	m_angularVelocity.z = m_angularVelocity.z + m_angularAcceleration.z * deltaTime;
	return m_angularVelocity;
}

Vector3 RigidBody::CalculateDrag(const float deltaTime)
{
	m_angularVelocity *= powf(m_angularDamping, deltaTime);
	return m_angularVelocity;
}

void RigidBody::CalculateAngularOrientation(const float deltaTime)
{
	m_orientation.addScaledVector(m_angularVelocity, deltaTime);
	m_orientation.normalise();

	XMMATRIX orientationMatrix = XMMATRIX();
	CalculateTransformMatrixRowMajor(orientationMatrix, m_transform->GetPosition(), m_orientation);

	m_transform->SetRotation(orientationMatrix);
}