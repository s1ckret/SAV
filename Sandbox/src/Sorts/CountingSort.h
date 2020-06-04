#pragma once

#include "SAV.h"

class CountingSort : public ISort
{
public:
	CountingSort( Array &array, std::shared_ptr<IDataRenderer> &dataRednderer );
	void Begin() override;
private:
};