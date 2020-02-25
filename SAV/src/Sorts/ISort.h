#pragma once
#include "Log.h"
#include "DataTypes.h"

class ISort
{
public:
	ISort(ArrayInfo& arr_info);
	virtual ~ISort() = default;

	virtual void Begin() = 0;
	std::string GetName() const	{ return name_;	}
protected:
	void Swap(int& lhs, int& rhs);
	void MarkColor(unsigned int index, ColorName color);
	void DisplaySorted();
	void SleepFor(unsigned int miliseconds);
protected:
	std::string name_;
	ArrayInfo& arr_info_;
};