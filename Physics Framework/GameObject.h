#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "vector3d.h"
#include "Debug.h"
#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"
using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform()const { return _transform; }
	Appearance* GetAppearance()const { return _appearance; }
	ParticleModel* GetParticleModel()const { return _particleModel; }

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);


private:
	string _type;

	GameObject * _parent;

	Transform* _transform;
	Appearance* _appearance;
	ParticleModel* _particleModel;
};

