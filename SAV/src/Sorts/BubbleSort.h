#pragma once

#include "ISort.h"

class BubbleSort : public ISort
{
public:
	BubbleSort(Array & array, std::shared_ptr<IDataRenderer> & dataRednderer);
    ~BubbleSort();

	void Begin() override;
private:
    
};