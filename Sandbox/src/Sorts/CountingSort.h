#pragma once

#include "SAV.h"

class CountingSort : public ISort
{
public:
  CountingSort(std::shared_ptr<IDataController>& dataController, 
               std::shared_ptr<IDataRenderer>& dataRednderer);
	void Begin() override;
private:
};