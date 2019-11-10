#include "RadixLsdSort.h"

RadixLsdSort::RadixLsdSort(ArrayInfo& arr_info) : ISort(arr_info)
{
	name_ = "RadixLsdSort";
}

void RadixLsdSort::Begin()
{
	for (unsigned int cutoff = 1; arr_info_.max_value / cutoff > 0; cutoff *= 10)
	{
		BeginCountingSort(arr_info_.arr, arr_info_.nElements, cutoff);
	}

	DisplaySorted();
	LOG_INFO("I am sorted !");
}

void RadixLsdSort::BeginCountingSort(int * arr, unsigned int nElements, unsigned int cutoff)
{
	const unsigned int max_value = 10;

	unsigned int * count_array = (unsigned int*)malloc(sizeof(unsigned int) * max_value);
	int * sorted_array = (int*)malloc(sizeof(int) * nElements);
	memset(count_array, 0, sizeof(unsigned int) * max_value);
	memset(sorted_array, 0, sizeof(int) * nElements);

	for (unsigned int i = 0; i < nElements; i++)
	{
		MarkColor(i, ColorName::Red);
		count_array[ (arr[i] / cutoff) % 10 ]++;
		SleepFor(8);
		MarkColor(i, ColorName::White);
	}

	for (unsigned int i = 1; i < max_value; i++)
	{
		count_array[i] += count_array[i - 1];
	}

	// Swapping arrays for rendering purpose;
	arr_info_.arr = sorted_array;

	for (int i = nElements - 1; i >= 0; i--)
	{
		unsigned int index = count_array[ (arr[i] / cutoff) % 10 ]-- - 1;
		MarkColor(index, ColorName::Magenta);
		sorted_array[index] = arr[i];
		SleepFor(7);
	}
	
	free(arr);
	free(count_array);
}

