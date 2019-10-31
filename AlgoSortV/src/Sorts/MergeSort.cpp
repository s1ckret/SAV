#include "MergeSort.h"

void MergeSort::Begin(int * mass, unsigned int nElements, Vec3* color_markers)
{
	color_markers_ = color_markers;
	MergeSortBegin(mass, 0, nElements - 1);
	for (unsigned int i = 0; i < nElements; i++)
	{
		color_markers_[i].Set(0.f, 1.f, 0.f);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
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
		color_markers_[left + i].Set(1.f, 1.f, 1.f);
		color_markers_[mid + j].Set(1.f, 1.f, 1.f);

		if (tempLeft[i] < tempRight[j])
		{
			mass[k] = tempLeft[i];
			i++;
			color_markers_[left + i].Set(1.f, 0.f, 0.f);
		}
		else
		{
			mass[k] = tempRight[j];
			j++;
			color_markers_[mid + j].Set(1.f, 0.f, 0.f);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		k++;
	}

	// Copy the remaining elements
	while (i < sizeLeft)
	{
		color_markers_[left + i].Set(1.f, 1.f, 1.f);
		mass[k] = tempLeft[i];
		i++;
		k++;
		color_markers_[left + i].Set(1.f, 0.f, 0.f);
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
	// Copy the remaining elements 
	while (j < sizeRight)
	{
		color_markers_[mid + j].Set(1.f, 1.f, 1.f);
		mass[k] = tempRight[j];
		j++;
		k++;
		color_markers_[mid + j].Set(1.f, 0.f, 0.f);
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
	}
	color_markers_[mid + j].Set(1.f, 1.f, 1.f);
	color_markers_[left + i].Set(1.f, 1.f, 1.f);

	delete[] tempLeft;
	delete[] tempRight;
}
