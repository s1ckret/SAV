#pragma once

#include "ISort.h"

class MergeSort : public ISort
{
public:
	MergeSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void MergeSortBegin(int * mass, unsigned int left, unsigned int right);
	void Merge(int * mass, unsigned int left, unsigned int mid, unsigned int right);
};