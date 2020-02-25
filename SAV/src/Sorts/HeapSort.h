#pragma once

#include "ISort.h"

class HeapSort : public ISort
{
public:
	HeapSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void HeapSortBegin(int * arr, int nElements);
	void Heapify(int * arr, unsigned int nElements, unsigned int index);
};