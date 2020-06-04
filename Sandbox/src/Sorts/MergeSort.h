#pragma once

#include "SAV.h"

class MergeSort : public ISort
{
public:
	MergeSort( Array &array, std::shared_ptr<IDataRenderer> &dataRednderer );

	void Begin() override;
private:
	void MergeSortBegin(unsigned int left, unsigned int right);
	void Merge(unsigned int left, unsigned int mid, unsigned int right);
};