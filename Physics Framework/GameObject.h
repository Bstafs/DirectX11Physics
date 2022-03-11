#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Vector3.h"
#include "Debug.h"
#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"
#include "RigidBody.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform()const { return m_transform; }
	Appearance* GetAppearance()const { return m_appearance; }
	ParticleModel* GetParticleModel()const { return m_particleModel; }
	RigidBody* GetRigidBody()const { return m_rigidbody; }

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);


private:
	string _type;

	GameObject * _parent;

	Transform* m_transform;
	Appearance* m_appearance;
	ParticleModel* m_particleModel;
	RigidBody* m_rigidbody;

	Vector3 velocity;
	Vector3 position;
};

