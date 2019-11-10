#pragma once

#include "ISort.h"

class QuickLSort : public ISort
{
public:
	QuickLSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void QuickLSortBegin(int * arr, int left, int right);
	unsigned int Partition(int * arr, int left, int right);
};