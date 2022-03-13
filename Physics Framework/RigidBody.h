#pragma once
#include "ParticleModel.h"
#include <directxmath.h>
#include <d3d11_1.h>
#include "Quaternion.h"
using namespace DirectX;

class RigidBody : public ParticleModel
{
public:
	RigidBody() {}
	RigidBody(shared_ptr<Transform> transform);
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
	void CalculateInertiaTensor(float dx, float dy, float dz);

};

