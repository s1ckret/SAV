#pragma once
#include "Log.h"

struct Vec3
{
	float x, y, z;
	void Set(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
};

class ISort
{
public:
	virtual void Begin(int * mass, unsigned int nElements, Vec3* color_markers) = 0;
};