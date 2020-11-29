#pragma once

#include "CoreMinimal.h"

class Vector4
{
public:
	float x;
	float y;
	float z;
	int w;
public:
	Vector4();
	Vector4(float x, float y, float z, int w = 0);
	~Vector4();
	Vector4 operator+(const Vector4& other);
	int operator[](const int& index);
	Vector4 operator-(const Vector4& other);
	FVector ToVector();
};

