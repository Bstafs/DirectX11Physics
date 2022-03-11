#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material)
{
	m_transform = new Transform();
	m_appearance = new Appearance(type, geometry, material);
	m_particleModel = new ParticleModel(velocity, position);
	m_rigidbody = new RigidBody();
}

GameObject::~GameObject()
{
}

void GameObject::Update(float t)
{
	m_transform->Update(t);
	m_particleModel->Update(t);
	m_rigidbody->Update(t);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	m_appearance->Draw(pImmediateContext);
}
