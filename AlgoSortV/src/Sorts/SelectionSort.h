#pragma once

#include "ISort.h"

class SelectionSort : public ISort
{
public:
	SelectionSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void SelectionSortBegin(int * arr, unsigned int nElements);
};