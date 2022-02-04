#pragma once

#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

class vector3d
{
public:
	//Variables
	float x, y, z;

	//Constructors
	vector3d(); //constructor
	vector3d(float x1, float y1, float z1 = 0); //construct with values.
	vector3d(const vector3d& vec); //copy constructor

   //Arithemetic Operators – note use of overloading
	vector3d operator+(const vector3d& vec); //addition
	vector3d& operator+=(const vector3d& vec);//assign new result to vector
	vector3d operator-(const vector3d& vec); //substraction
	vector3d& operator-=(const vector3d& vec);//assign new result to vector
	vector3d operator*(float value); //multiplication
	vector3d& operator*=(float value); //assign new result to vector.
	vector3d operator/(float value); //division
	vector3d& operator/=(float value); //assign new result to vector
	vector3d& operator=(const vector3d& vec);

	inline double Length()const;

	//Vector operations
    inline float DotProduct(const vector3d& vec); //scalar dot_product
	inline vector3d CrossProduct(const vector3d& vec);
	inline vector3d Normalization(const vector3d& vec); //normalized vector

	//Scalar Operations
	inline float Square(); //gives square of the vector
	inline float Distance(const vector3d& vec1, const vector3d& vec2); //distance between two vectors
	inline float Magnitude(const vector3d& vec); //magnitude of the vector
};