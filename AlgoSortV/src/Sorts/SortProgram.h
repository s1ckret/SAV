#pragma once

#include <thread>
#include <memory>

#include "ISort.h"
#include "BubbleSort.h"
#include "MergeSort.h"

#include "Graphics\Renderer.h"
#include "Graphics\SortRenders\SortRenderer.h"

enum class SortType
{
	BUBBLE,
	MERGE,
	SORTS_COUNT = 2
};

class SortProgram
{
public:
	static SortProgram& Get();

	void GenerateMassive(const unsigned int nElements, const int max_value);
	void SetMethod(SortType sort);
	void Begin();
	void ShuffleMassive();
	void Render(const Renderer& renderer);
private:
	SortProgram();
	~SortProgram();
	void Join();
private:
	int* mass_;
	int max_value_;
	unsigned int nElements_;
	Vec3 * color_markers_;
	ISort* sort_;
	SortRenderer* renderer_;

	std::thread thread_sort;

	static ISort* SORTS[(unsigned int)SortType::SORTS_COUNT];
};