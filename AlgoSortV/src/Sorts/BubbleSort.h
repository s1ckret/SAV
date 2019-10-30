#pragma once

#include "ISort.h"

class BubbleSort : public ISort
{
public:
	void operator()(int * mass, unsigned int nElements) override;

};