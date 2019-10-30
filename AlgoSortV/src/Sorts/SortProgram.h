#pragma once

#include <thread>
#include <memory>

#include "ISort.h"
#include "BubbleSort.h"
#include "MergeSort.h"

#include "Graphics\Renderer.h"
#include "Graphics\SortRenders\ISortRenderer.h"
#include "Graphics\SortRenders\BubbleSortRenderer.h"

enum class SortType
{
	BUBBLE,
	MERGE,
	QUICK,
	SORTS_COUNT = 3
};

class SortProgram
{
public:
	SortProgram();
	~SortProgram();

	void GenerateMassive(unsigned int count);
	void SetMethod(SortType sort);
	void Begin();
	void ShuffleMassive();
	void Render(const Renderer& renderer);

private:
	int* mass_;
	unsigned int nElements_;
	ISort* sort_;
	ISortRenderer* renderer_;

	std::thread thread_sort;
};