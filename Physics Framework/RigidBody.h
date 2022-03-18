#pragma once
#include "ParticleModel.h"
#include <directxmath.h>
#include <d3d11_1.h>
#include "Quaternion.h"
#include "Vector3.h"
using namespace DirectX;

class RigidBody : public ParticleModel
{
public:
	RigidBody();
	~RigidBody();
	void Update(const float deltaTime);
private:

	XMFLOAT3 m_angularAcceleration;

	XMFLOAT3X3 m_inertiaTensor;

	Vector3 m_torque;
	Vector3 m_angularVelocity;

	float m_angularDamping;

	Quaternion m_orientation;
private:
	Vector3 CalculateTorque();
	XMFLOAT3X3 CalculateInertiaTensor(float dx, float dy, float dz);
	XMFLOAT3 CalculateAngularAcceleration();
	Vector3 CalculateAngularVelocity(const float deltaTime);
	Vector3 CalculateDrag(const float deltaTime);
	void CalculateAngularOrientation(const float deltaTime);
};

