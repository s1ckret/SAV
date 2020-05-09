#pragma once

#include "ISort.h"

class QuickLSort : public ISort
{
public:
	QuickLSort( Array &array, std::shared_ptr<IDataRenderer> &dataRednderer );

	void Begin() override;
private:
	void QuickLSortBegin(int left, int right);
	int Partition(int left, int right);
};