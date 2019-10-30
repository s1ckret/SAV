#pragma once
#include "ISortRenderer.h"


class BubbleSortRenderer : public ISortRenderer
{
public:
	BubbleSortRenderer(int * mass, unsigned int nElements);
	~BubbleSortRenderer();

	void Draw(const Renderer & renderer) override;

private:
};