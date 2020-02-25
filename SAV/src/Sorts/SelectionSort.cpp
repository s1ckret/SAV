#include "SelectionSort.h"

SelectionSort::SelectionSort(ArrayInfo & arr_info) : ISort(arr_info)
{
	name_ = "SelectionSort";
}

void SelectionSort::Begin()
{
	SelectionSortBegin(arr_info_.arr, arr_info_.nElements);
	LOG_INFO("I am sorted !");
}

void SelectionSort::SelectionSortBegin(int * arr, unsigned int nElements)
{
	for (unsigned int i = 0; i < nElements; i++)
	{
		unsigned int min_index = i;
		MarkColor(i, ColorName::Blue);
		for (unsigned int j = i + 1; j < nElements; j++)
		{
			MarkColor(j, ColorName::Red);
			if (arr[min_index] > arr[j])
			{
				min_index = j;
			}
			SleepFor(1);
			MarkColor(j, ColorName::White);
		}
		Swap(arr[i], arr[min_index]);
		MarkColor(i, ColorName::Green);
	}
}


