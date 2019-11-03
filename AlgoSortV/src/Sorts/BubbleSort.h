#pragma once

#include "ISort.h"

class BubbleSort : public ISort
{
public:
	BubbleSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void BubbleSortBegin(int * arr, unsigned int nElements);
};