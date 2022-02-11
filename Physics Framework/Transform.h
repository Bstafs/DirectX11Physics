#pragma once
#include "vector3d.h"
#include <directxmath.h>
#include <d3d11_1.h>
using namespace DirectX;
class Transform
{
public:
	Transform();
	~Transform();
	void Update(float t);

	// Setters and Getters for position/rotation/scale
	void SetPosition(vector3d position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	vector3d GetPosition() const { return _position; }

	void SetScale(vector3d scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	vector3d GetScale() const { return _scale; }

	void SetRotation(vector3d rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	vector3d GetRotation() const { return _rotation; }
private:
	vector3d _position;
	vector3d _rotation;
	vector3d _scale;
	XMFLOAT4X4 _world;
};

