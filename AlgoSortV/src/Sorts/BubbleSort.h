#pragma once

#include "ISort.h"

class BubbleSort : public ISort
{
public:
	void Begin(int * mass, unsigned int nElements) override;

};