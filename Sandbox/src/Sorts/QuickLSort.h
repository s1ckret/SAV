#pragma once

#include "SAV.h"

class QuickLSort : public ISort
{
public:
  QuickLSort(std::shared_ptr<IDataController>& dataController,
             std::shared_ptr<IDataRenderer>& dataRednderer);

	void Begin() override;
private:
	void QuickLSortBegin(int left, int right);
	int Partition(int left, int right);
};