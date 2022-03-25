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
	ParticleModel();
	~ParticleModel();

	void SetTransform(Transform* tf) { m_transform = tf; }
	Transform* GetTransform() { return m_transform; }

	void Update(const float deltaTime);

	void MoveConstantVelocity(const float deltaTime);
	void MoveConstantAcceleration();

	// Setters and Getters for velocity/acceleration/netforce/mass
	Vector3 GetVelocity() const { return m_velocity; }
	void SetVelocity(Vector3 velocity) { m_velocity = velocity; }
	void SetVelocity(float x, float y, float z) { m_velocity.x = x; m_velocity.y = y; m_velocity.z = z; }

	Vector3 GetAcceleration() const { return m_acceleration; }
	void SetAcceleration(Vector3 acceleration) { m_acceleration = acceleration; }
	void SetAcceleration(float x, float y, float z) { m_acceleration.x = x; m_acceleration.y = y; m_acceleration.z = z; }

	Vector3 GetNetForce() const { return m_netForce; }
	void SetNetForce(Vector3 netForce) { m_netForce = netForce; }
	void SetNetForce(float x, float y, float z) { m_netForce.x = x; m_netForce.y = y; m_netForce.z = z; }

	void SetMass(float newMass) { m_mass = newMass; }
	float GetMass() const { return m_mass; }

	inline Vector3 AddForce(Vector3 force) { m_netForce = m_netForce + force; }
	void AddForce(float x, float y, float z) { m_netForce.x = x, m_netForce.y = y, m_netForce.z = z; }

private:
	void Gravity();
	void UpdatePosition(const float deltaTime);


protected:
	Vector3 m_netForce;
	Vector3 m_velocity;
	Vector3 m_acceleration;

	Transform* m_transform;

	float m_mass;
private:
	float m_gravity;
	float m_weight;

	bool m_hasGravity;
};

