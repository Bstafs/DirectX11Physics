#include "vector3d.h"

vector3d::vector3d() //constructor
{
	x = 0;
	y = 0;
	z = 0;
}

vector3d::vector3d(float x1, float y1, float z1) //construct with values.
{
	x = x1;
	y = y1;
	z = z1;
}

//The copy constructor is required for the same reason as above.
vector3d::vector3d(const vector3d& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

//Addition
vector3d vector3d ::operator+(const vector3d& vec)
{
   return vector3d(x + vec.x, y + vec.y, z + vec.z);
}

vector3d& vector3d ::operator+=(const vector3d& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;
}

//Substraction//
vector3d vector3d ::operator-(const vector3d& vec)
{
	return vector3d(x - vec.x, y - vec.y, z - vec.z);
}

vector3d& vector3d::operator-=(const vector3d& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

//scalar multiplication
vector3d vector3d ::operator*(float value)
{
	return vector3d(x * value, y * value, z * value);
}

vector3d& vector3d::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;

	return *this;
}

//scalar division
vector3d vector3d ::operator/(float value)
{
	assert(value != 0); //prevent divide by 0
	//similar to multiplication
	return vector3d(x / value, y / value, z / value);
}

vector3d& vector3d ::operator/=(float value)
{
	assert(value != 0);
	//similar to multiplication
	x /= value;
	y /= value;
	z /= value;

	return *this;
}

vector3d& vector3d::operator=(const vector3d& vec)
{
	//similar to addition
	x = vec.x;
	y = vec.y;
	z = vec.z;

	return *this;
}

inline double vector3d::Length()const
{
	return sqrt(x * x + y * y + z * z);
}

//Dot product
inline float vector3d::DotProduct(const vector3d& vec)
{
	return (x * vec.x + y * vec.y + z * vec.z);
}

//Cross Product
inline vector3d vector3d::CrossProduct(const vector3d& vec)
{

	//Calculate the terms (ni,nj,nk) using the dot product formula

	//Then use to construct a vector using those terms and return

	// as an example using vec to represent second vector

	// the term ni in the output (new)vector is calculated as

	// float ni=y*vec.z-z*vec.y;


}
// Vector Length
inline float vector3d::Magnitude(const vector3d& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
// Vector Normalize
inline vector3d vector3d::Normalization(const vector3d& vec)
{
	vector3d vector = vec;
	double vector_length = vector.Length();

	if (vector_length > std::numeric_limits<double>::epsilon())
	{
		this->x /= vector_length;
		this->y /= vector_length;
		this->z /= vector_length;
	}

	return vector;
}
// Vector Square
inline float vector3d::Square()
{
	return x * x + y * y + z * z;
}

//Vector Distance
inline float vector3d::Distance(const vector3d& vec1, const vector3d& vec2)
{
	float ySep = vec2.y - vec1.y;
	float xSep = vec2.x - vec1.x;
	float zSep = vec2.z - vec1.z;

	return sqrt(ySep * ySep + xSep * xSep + zSep * zSep);
}