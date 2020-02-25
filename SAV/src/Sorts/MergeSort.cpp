#include "MergeSort.h"
#include "SortProgram.h"

MergeSort::MergeSort(ArrayInfo& arr_info) : ISort(arr_info)
{
	name_ = "MergeSort";
}

void MergeSort::Begin()
{
	MergeSortBegin(arr_info_.arr, 0, arr_info_.nElements - 1);
	DisplaySorted();
	LOG_INFO("I am sorted !");
}

void MergeSort::MergeSortBegin(int * mass, unsigned int left, unsigned int right)
{
	if (left < right)
	{
		unsigned int mid = (left + right) / 2;

		MergeSortBegin(mass, left, mid);
		MergeSortBegin(mass, mid + 1, right);

		Merge(mass, left, mid, right);
	}
}

void MergeSort::Merge(int * mass, unsigned int left, unsigned int mid, unsigned int right)
{
	// Finding arrays size
	unsigned int sizeLeft = mid - left + 1;
	unsigned int sizeRight = right - mid;
	// Createing temporaly arrays
	int *tempLeft = new int [sizeLeft];
	int *tempRight = new int[sizeRight];
	// Copy data into Left array
	for (unsigned int i = 0; i < sizeLeft; i++) 
	{
		tempLeft[i] = mass[left + i];
	}
	// Copy data into Right array
	for (unsigned int i = 0; i < sizeRight; i++) 
	{
		tempRight[i] = mass[mid + i + 1];
	}

	// Merging
	unsigned int i = 0, j = 0, k = left;
	while (i < sizeLeft && j < sizeRight)
	{
		MarkColor(left + i, ColorName::White);
		MarkColor(mid + j, ColorName::White);

		if (tempLeft[i] < tempRight[j])
		{
			mass[k] = tempLeft[i];
			i++;
			MarkColor(left + i, ColorName::Red);
		}
		else
		{
			mass[k] = tempRight[j];
			j++;
			MarkColor(mid + j, ColorName::Red);
		}
		SleepFor(2);
		k++;
	}

	// Copy the remaining elements
	while (i < sizeLeft)
	{
		MarkColor(left + i, ColorName::White);
		mass[k] = tempLeft[i];
		i++;
		k++;
		MarkColor(left + i, ColorName::Red);
		SleepFor(2);
	}
	// Copy the remaining elements 
	while (j < sizeRight)
	{
		MarkColor(mid + j, ColorName::White);
		mass[k] = tempRight[j];
		j++;
		k++;
		MarkColor(mid + j, ColorName::Red);
		SleepFor(2);
	}
	MarkColor(mid + j, ColorName::White);
	MarkColor(left + i, ColorName::White);

	delete[] tempLeft;
	delete[] tempRight;
}
