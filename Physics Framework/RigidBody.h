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
	XMFLOAT3 CalculateTorque();
	void CalculateInertiaTensor(float dx, float dy, float dz);
	void CalculateAngularAcceleration();
private:
	Vector3 m_position = Vector3(0.0,0.0,0.0);
	Vector3 m_force = Vector3(0.0,0.0,3.0);
	XMFLOAT3 m_torque;
	XMFLOAT3X3 m_inertiaTensor;
	XMFLOAT3 m_angularAcceleration;
	float m_angularDamping = 0.99;
};

