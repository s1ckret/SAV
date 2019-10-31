#pragma once
#include "Log.h"

class ISort
{
public:
	virtual void Begin(int * mass, unsigned int nElements) = 0;
};