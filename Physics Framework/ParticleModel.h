#pragma once
#include "Vector3.h"
#include <directxmath.h>
#include <d3d11_1.h>
using namespace DirectX;

class ParticleModel
{
public:
	ParticleModel(Vector3 velocity, Vector3 position);
	~ParticleModel();

	void Update(float t);

	void moveConstantVelocity(const float deltaTime);

	Vector3 GetVelocity();
	void SetVelocity(Vector3 velocity);

	Vector3 GetAcceleration();
	void SetAcceleration(Vector3 acceleration);

	Vector3 GetPosition();
	void SetPosition(Vector3 position);



private:
	Vector3 m_velocity;
	Vector3 m_acceleration;
	Vector3 m_position;
	Vector3 m_displacement;
};

