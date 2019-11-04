#include "ShellSort.h"

ShellSort::ShellSort(ArrayInfo & arr_info) : ISort(arr_info)
{
	name_ = "ShellSort";
}

void ShellSort::Begin()
{
	ShellSortBegin(arr_info_.arr, arr_info_.nElements);
	DisplaySorted();
	LOG_INFO("I am sorted !");
}

void ShellSort::ShellSortBegin(int * arr, unsigned int nElements)
{
	for (unsigned int gap = nElements / 2; gap > 0; gap /= 2)
	{
		for (unsigned int i = gap; i < nElements; i++)
		{
			unsigned int temp = arr[i];
			unsigned int j = i;
			MarkColor(i, ColorName::Blue);
			for (j; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
				MarkColor(j - gap, ColorName::Red);
				SleepFor(10);
				MarkColor(j - gap, ColorName::White);
			}
			SleepFor(10);
			MarkColor(i, ColorName::White);

			arr[j] = temp;
		}
	}
}


