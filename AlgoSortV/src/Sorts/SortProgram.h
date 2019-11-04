#pragma once

#include <thread>
#include <memory>

#include "ISort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "SelectionSort.h"

#include "Graphics\Renderer.h"
#include "Graphics\SortRenders\SortRenderer.h"

class SortProgram
{
public:
	static SortProgram& Get();

	void GenerateMassive(const unsigned int nElements, const int max_value);
	void SetMethod(SortType sort);
	void Begin();
	void ShuffleMassive();
	void Render(const Renderer& renderer);
	
	std::string GetSortName(SortType sort) const;
private:
	SortProgram();
	~SortProgram();
	void Join();
	void InitSorts();
private:
	ISort* sort_;
	ISort** SORTS;

	std::thread thread_sort;

	ArrayInfo arr_info_;

	SortRenderer* renderer_;

};