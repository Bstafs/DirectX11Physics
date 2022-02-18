#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material)
{
	_transform = new Transform();
	_appearance = new Appearance(type, geometry, material);
	//_particleModel = new ParticleModel();
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	_transform->Update(t);
	_particleModel->Update(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
