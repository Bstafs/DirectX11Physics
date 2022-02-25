#pragma once
#include "vector3d.h"
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
	void SetPosition(Vector3 position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	Vector3 GetPosition() const { return _position; }

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

private:
	Vector3 _position;
	Quaternion _rotation;
	Vector3 _scale;
	XMFLOAT4X4 _world;
};

