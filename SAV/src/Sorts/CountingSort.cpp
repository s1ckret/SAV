#include "CountingSort.h"

CountingSort::CountingSort(ArrayInfo& arr_info) : ISort(arr_info)
{
	name_ = "CountingSort";
}

void CountingSort::Begin()
{
	BeginCountingSort(arr_info_.arr, arr_info_.nElements, abs(arr_info_.max_value));
	DisplaySorted();
	LOG_INFO("I am sorted !");
}

void CountingSort::BeginCountingSort(int * arr, unsigned int nElements, unsigned int max_value)
{
	unsigned int * count_array = (unsigned int*)malloc(sizeof(unsigned int) * max_value);
	int * sorted_array = (int*)malloc(sizeof(int) * nElements);
	memset(count_array, 0, sizeof(unsigned int) * max_value);
	memset(sorted_array, 0, sizeof(int) * nElements);

	for (unsigned int i = 0; i < nElements; i++)
	{
		MarkColor(i, ColorName::Red);
		count_array[arr[i]]++;
		SleepFor(8);
		MarkColor(i, ColorName::White);
	}

	for (unsigned int i = 1; i < max_value; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	// Swapping arrays for rendering purpose;
	arr_info_.arr = sorted_array;

	for (unsigned int i = 0; i < nElements; i++)
	{
		unsigned int index = count_array[arr[i]]-- - 1;
		MarkColor(index, ColorName::Green);
		sorted_array[index] = arr[i];
		SleepFor(7);
	}
	free(arr);
	free(count_array);
}

