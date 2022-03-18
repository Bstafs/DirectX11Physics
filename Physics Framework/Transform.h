#pragma once
#include "Vector3.h"
#include <directxmath.h>
#include <d3d11_1.h>
#include "Quaternion.h"
using namespace DirectX;
class Transform
{
public:
	Transform();
	~Transform();
	void Update(float t);

	// Setters and Getters for position/rotation/scale
	void SetPosition(Vector3 position) { m_position = position; }
	void SetPosition(float x, float y, float z) { m_position.x = x; m_position.y = y; m_position.z = z; }

	Vector3 GetPosition() const { return m_position; }

	void SetScale(Vector3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	Vector3 GetScale() const { return _scale; }

	void SetRotation(Vector3 rotation) { SetRotation(rotation.x,rotation.y,rotation.z); }
	void SetRotation(float x, float y, float z) 
	{
		XMVECTOR xmVector = XMQuaternionRotationMatrix(XMMatrixRotationX(x) * XMMatrixRotationX(y) * XMMatrixRotationX(z));
		XMFLOAT4 quaternionFloat;
		XMStoreFloat4(&quaternionFloat, xmVector);
		_rotation = Quaternion(quaternionFloat.w, quaternionFloat.x, quaternionFloat.y, quaternionFloat.z);
		_rotation.normalise();
	}

	Quaternion GetRotation() const { return _rotation; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

protected:

	Vector3 m_position;

private:
	Quaternion _rotation;
	Vector3 _scale;
	XMFLOAT4X4 _world;
};

