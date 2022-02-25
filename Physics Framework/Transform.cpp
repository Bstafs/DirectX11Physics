#include "Transform.h"

Transform::Transform()
{
	XMVECTOR XMVectorToQuaternion = XMQuaternionRotationMatrix(XMMatrixRotationX(0.0f) * XMMatrixRotationX(0.0f) * XMMatrixRotationX(0.0f));
	XMFLOAT4 XMFloat4Thing;
	XMStoreFloat4(&XMFloat4Thing, XMVectorToQuaternion);

	_position = Vector3();
	_rotation = Quaternion(XMFloat4Thing.w, XMFloat4Thing.x, XMFloat4Thing.y, XMFloat4Thing.z);
	_rotation.normalise();
	_scale = Vector3(1.0f, 1.0f, 1.0f);
}

Transform::~Transform()
{

}

void Transform::Update(float t)
{

	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation;
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);



	CalculateTransformMatrixRowMajor(rotation, Vector3(), _rotation );
	XMStoreFloat4x4(&_world, scale * rotation * translation);
	XMStoreFloat4x4(&_world, this->GetWorldMatrix());
}
