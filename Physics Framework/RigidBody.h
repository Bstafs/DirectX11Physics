#pragma once
#include "Vector3.h"
#include "ParticleModel.h"
#include <directxmath.h>
#include <d3d11_1.h>
#include "Quaternion.h"
using namespace DirectX;

class RigidBody
{
public:
	RigidBody();
	~RigidBody();
	void CalculateTorque();
	void CalculateInertiaTensor(float dx, float dy, float dz);
	void CalculateAngularAcceleration();
	void CalculateAngularVelocity();
	void DampingForce();
	void CalculateAngularOrientation();
private:
	XMVECTOR m_position;
	XMVECTOR m_force;
	XMFLOAT3 m_torque;
	XMFLOAT3X3 m_inertiaTensor;
	XMFLOAT3 m_angularAcceleration;
	XMFLOAT3 m_angularVelocity;
	float m_angularDamping = 0.99;
};

