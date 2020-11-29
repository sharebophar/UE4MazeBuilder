#include "Vector4.h"



Vector4::Vector4()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}


Vector4::~Vector4()
{
}

Vector4::Vector4(float x, float y, float z, int w = 0)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}


Vector4 Vector4::operator+(const Vector4& other)
{
	Vector4 v;
	v.x = this->x + other.x;
	v.y = this->y + other.y;
	v.z = this->z + other.z;
	v.w = this->w + other.w;
	return v;
}

int Vector4::operator[](const int& index)
{
	Vector4 v;
	if (index == 0) return (int)(v.x);
	else if (index == 1) return (int)(v.y);
	else if (index == 2) return (int)(v.z);
	else if (index == 3) return v.w;
	else return 0;
}

Vector4 Vector4::operator-(const Vector4& other)
{
	Vector4 v;
	v.x = this->x - other.x;
	v.y = this->y - other.y;
	v.z = this->z - other.z;
	v.w = this->w - other.w;
	return v;
}

FVector Vector4::ToVector()
{
	return FVector(x, y, z);
}