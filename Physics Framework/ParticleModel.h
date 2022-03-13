#pragma once
#include "Vector3.h"
#include "Transform.h"
#include <directxmath.h>
#include <d3d11_1.h>
using namespace DirectX;
using namespace std;
class ParticleModel
{
public:
	ParticleModel() {}
	ParticleModel(shared_ptr<Transform> transform);
	~ParticleModel();

	shared_ptr<Transform> GetTransform() const { return m_transform; }

	void Update(const float deltaTime);

	void MoveConstantVelocity(const float deltaTime);
	void MoveConstantAcceleration(const float deltaTime);

	Vector3 GetVelocity() const { return m_velocity; }
	void SetVelocity(Vector3 velocity) { m_velocity = velocity; }
	void SetVelocity(float x, float y, float z) { m_velocity.x = x; m_velocity.y = y; m_velocity.z = z; }

	Vector3 GetAcceleration() const { return m_acceleration; }
	void SetAcceleration(Vector3 acceleration) { m_acceleration = acceleration; }
	void SetAcceleration(float x, float y, float z) { m_acceleration.x = x; m_acceleration.y = y; m_acceleration.z = z; }

	Vector3 GetPosition() const { return m_position; }
	void SetPosition(Vector3 position)  { m_position = position; }
	void SetPosition(float x, float y, float z) { m_position.x = x; m_position.y = y; m_position.z = z; }

	Vector3 GetNetForce() const { return m_netForce; }
	void SetNetForce(Vector3 netForce) { m_netForce = netForce; }
	void SetNetForce(float x, float y, float z) { m_netForce.x = x; m_netForce.y = y; m_netForce.z = z; }

	void SetMass(float newMass) { m_mass = newMass; }
	float GetMass() const { return m_mass; }

private:
	void Gravity();

protected:
	Vector3 m_netForce;
	Vector3 m_velocity;
	Vector3 m_position;
	Vector3 m_acceleration;
	Vector3 m_prevPosition;

	float m_mass = 50.0f;

	shared_ptr<Transform> m_transform;
private:
	float m_gravity = 9.8f;
	float m_weight = 10.0f;
	float m_weightLimit = 0.002f;
};

