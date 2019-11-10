#include "QuickLSort.h"
#include "SortProgram.h"

QuickLSort::QuickLSort(ArrayInfo& arr_info) : ISort(arr_info)
{
	name_ = "QuickLSort";
}

void QuickLSort::Begin()
{
	QuickLSortBegin(arr_info_.arr, 0, arr_info_.nElements - 1);
	DisplaySorted();
	LOG_INFO("I am sorted !");
}

void QuickLSort::QuickLSortBegin(int * arr, int left, int right)
{
	if (left < right)
	{
		int pivot_index = Partition(arr, left, right);

		QuickLSortBegin(arr, left, pivot_index - 1);
		QuickLSortBegin(arr, pivot_index + 1, right);
	}
}

unsigned int QuickLSort::Partition(int * arr, int left, int right)
{
	int pivot = arr[right];
	MarkColor(right, ColorName::Blue);
	unsigned int i = left - 1;

	for (unsigned int j = left; j < right; j++)
	{
		MarkColor(j, ColorName::Red);
		if (arr[j] < pivot)
		{
			i++;
			MarkColor(i, ColorName::Magenta);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		SleepFor(5);
		MarkColor(i, ColorName::White);
		MarkColor(j, ColorName::White);
	}
	i++;
	int temp = arr[right];
	arr[right] = arr[i];
	arr[i] = temp;
	MarkColor(right, ColorName::Green);

	return i;
}
