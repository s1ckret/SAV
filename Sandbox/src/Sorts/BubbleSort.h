#pragma once

#include "SAV.h"

class BubbleSort : public ISort
{
public:
  BubbleSort(std::shared_ptr<IDataController>& dataController,
        std::shared_ptr<IDataRenderer>& dataRednderer);
  ~BubbleSort();

	void Begin() override;
private:
    
};