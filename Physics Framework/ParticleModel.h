#pragma once
#include "vector3d.h"
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

	Vector3 GetPosition();
	void SetPosition(Vector3 position);

private:
	Vector3 m_velocity;
	Vector3 m_position;
};

