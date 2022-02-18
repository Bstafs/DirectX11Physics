#pragma once
#include "vector3d.h"
#include <directxmath.h>
#include <d3d11_1.h>
using namespace DirectX;

class ParticleModel
{
public:
	ParticleModel(vector3d velocity, vector3d position);
	~ParticleModel();

	void Update(float t);

	void moveConstantVelocity(const float deltaTime);

	vector3d GetVelocity();
	void SetVelocity(vector3d velocity);

	vector3d GetPosition();
	void SetPosition(vector3d position);

private:
	vector3d m_velocity;
	vector3d m_position;
};

