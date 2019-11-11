#include "BubbleSort.h"

BubbleSort::BubbleSort(ArrayInfo & arr_info) : ISort(arr_info)
{
	name_ = "BubbleSort";
}

void BubbleSort::Begin()
{
	BubbleSortBegin(arr_info_.arr, arr_info_.nElements);
	LOG_INFO("I am sorted !");
}

void BubbleSort::BubbleSortBegin(int * arr, unsigned int nElements)
{
	for (unsigned int i = 0; i < nElements; i++)
	{
		for (unsigned int j = 0; j < nElements - i - 1; j++)
		{
			MarkColor(j, ColorName::Red);
			MarkColor(j + 1, ColorName::Red);
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
			SleepFor(1);
			MarkColor(j, ColorName::White);
		}
		MarkColor(nElements - 1 - i, ColorName::Green);
	}
}


