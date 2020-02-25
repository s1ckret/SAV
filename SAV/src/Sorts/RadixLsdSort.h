#pragma once

#include "ISort.h"

class RadixLsdSort : public ISort
{
public:
	RadixLsdSort(ArrayInfo& arr_info);
	void Begin() override;
private:
	void BeginCountingSort(int * arr, unsigned int nElements, unsigned int cutoff);
};