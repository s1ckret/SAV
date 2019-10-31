#pragma once

#include "ISort.h"

class MergeSort : public ISort
{
public:
	void Begin(int * mass, unsigned int nElements, Vec3* color_markers) override;
private:
	void MergeSortBegin(int * mass, unsigned int left, unsigned int right);
	void Merge(int * mass, unsigned int left, unsigned int mid, unsigned int right);
	Vec3* color_markers_;
};