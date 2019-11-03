#pragma once

#include "ISort.h"

class CountingSort : public ISort
{
public:
	CountingSort(ArrayInfo& arr_info);
	void Begin() override;
private:
	void BeginCountingSort(int * arr, unsigned int nElements, unsigned int max_value);
};