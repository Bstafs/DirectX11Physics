#include "RigidBody.h"

RigidBody::RigidBody(shared_ptr<Transform> transform) : ParticleModel(transform)
{
	m_angularDamping = 0.9;
}

RigidBody::~RigidBody()
{

}

void RigidBody::Update(const float deltaTime)
{
	// Calculate Torque
	m_torque = m_position.CrossProduct(m_netForce);

	//Calculate Inertia Tensor
	CalculateInertiaTensor(1.0f,1.0f,1.0f);

	//Calculate Angular Acceleration
	XMMATRIX inverted = XMMatrixInverse(nullptr, XMLoadFloat3x3(&m_inertiaTensor));
	XMStoreFloat3(&m_angularAcceleration, XMVector3Transform(m_torque, inverted));

	//Calculate Angular Velocity
	m_angularVelocity = m_angularVelocity + m_angularAcceleration * deltaTime;

	//Calculate Drag
	m_angularVelocity *= powf(m_angularDamping, deltaTime);

	//Calculate Angular Orientation
	m_orientation.addScaledVector(m_angularVelocity, deltaTime);
	m_orientation.normalise();

	XMMATRIX matrix = XMMATRIX();
	CalculateTransformMatrixRowMajor(matrix, m_position, m_orientation);
}

void RigidBody::CalculateInertiaTensor(float dx, float dy, float dz)
{
	m_inertiaTensor = XMFLOAT3X3();
	m_inertiaTensor._11 = (1 / 12) * m_mass * (dy * dy + dz * dz); // change 1.0 to mass // _11 _12 _13
 	m_inertiaTensor._22 = (1 / 12) * m_mass * (dx * dx + dz * dz);                       // _21 _22 _23
 	m_inertiaTensor._33 = (1 / 12) * m_mass * (dx * dx + dy * dy);                       // _31 _32 _33
}
