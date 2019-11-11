#include "ISort.h"

ISort::ISort(ArrayInfo & arr_info) :
	arr_info_(arr_info)
{}

void ISort::Swap(int & lhs, int & rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void ISort::MarkColor(unsigned int index, ColorName color)
{
	arr_info_.markers[index].Set(color);
}

void ISort::DisplaySorted()
{
	for (unsigned int i = 0; i < arr_info_.nElements; i++)
	{
		arr_info_.markers[i].Set(ColorName::Green);
		SleepFor(2);
	}
}

void ISort::SleepFor(unsigned int miliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}
