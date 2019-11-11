#include "HeapSort.h"
#include "SortProgram.h"

HeapSort::HeapSort(ArrayInfo& arr_info) : ISort(arr_info)
{
	name_ = "HeapSort";
}

void HeapSort::Begin()
{
	HeapSortBegin(arr_info_.arr, arr_info_.nElements);
	LOG_INFO("I am sorted !");
}

void HeapSort::HeapSortBegin(int * arr, int nElements)
{
	for (int i = nElements / 2 - 1; i >= 0; i--)
	{
		Heapify(arr, nElements, i);
	}

	for (int i = nElements - 1; i >= 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;

		MarkColor(i, ColorName::Green);

		Heapify(arr, i, 0);
	}

}

void HeapSort::Heapify(int * arr, unsigned int nElements, unsigned int index)
{
	unsigned int max_value_index = index;
	unsigned int left_index = 2 * max_value_index + 1;
	unsigned int right_index = 2 * max_value_index + 2;
	MarkColor(index, ColorName::Blue);

	if (left_index < nElements && arr[left_index] > arr[max_value_index])
	{
		max_value_index = left_index;
		MarkColor(left_index, ColorName::Blue);
	}

	if (right_index < nElements && arr[right_index] > arr[max_value_index])
	{
		max_value_index = right_index;
		MarkColor(right_index, ColorName::Blue);
	}

	SleepFor(30);

	MarkColor(index, ColorName::White);
	if (max_value_index == index) return;

	MarkColor(left_index, ColorName::White);
	MarkColor(right_index, ColorName::White);


	int temp = arr[max_value_index];
	arr[max_value_index] = arr[index];
	arr[index] = temp;

	Heapify(arr, nElements, max_value_index);
}
