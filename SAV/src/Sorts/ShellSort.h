#pragma once

#include "ISort.h"

class ShellSort : public ISort
{
public:
	ShellSort(ArrayInfo& arr_info);

	void Begin() override;
private:
	void ShellSortBegin(int * arr, unsigned int nElements);
};