#pragma once

#include "ISort.h"

class BubbleSort : public ISort
{
public:
	void Begin(int * mass, unsigned int nElements, Vec3* color_markers) override;

};