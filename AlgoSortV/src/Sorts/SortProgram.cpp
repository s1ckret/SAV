#include "SortProgram.h"


SortProgram::SortProgram()
{
	InitSorts();
}

SortProgram::~SortProgram()
{
	if (thread_sort.joinable())
	{
		thread_sort.join();
	}
}

SortProgram & SortProgram::Get()
{
	static SortProgram sortProgram;
	return sortProgram;
}

void SortProgram::GenerateMassive(const unsigned int nElements, const int max_value)
{
	arr_info_.max_value = max_value;
	if (arr_info_.nElements != nElements)
	{
		arr_info_.nElements = nElements;
		if (arr_info_.arr)
		{
			free(arr_info_.arr);
			free(arr_info_.markers);
		}
		arr_info_.arr = (int*)malloc(sizeof(int) * arr_info_.nElements);
		arr_info_.markers = (Color*)malloc(sizeof(Color) * arr_info_.nElements);
	}
	for (unsigned int i = 0; i < arr_info_.nElements; i++)
	{
		arr_info_.arr[i] = rand() % arr_info_.max_value;
	}
	ShuffleMassive();
	if (!renderer_)
	{
		renderer_ = new SortRenderer(arr_info_);
	}
}

void SortProgram::Begin()
{
	Join();
	thread_sort = std::move(std::thread(&ISort::Begin, std::ref(sort_)));
}

void SortProgram::ShuffleMassive()
{
	for (unsigned int i = 0; i < arr_info_.nElements; i++)
	{
		unsigned int randomIndex = rand() % arr_info_.nElements;
		int temp = arr_info_.arr[i];
		arr_info_.arr[i] = arr_info_.arr[randomIndex];
		arr_info_.arr[randomIndex] = temp;

		arr_info_.markers[i].Set(ColorName::White);
	}
}

void SortProgram::Render(const Renderer & renderer)
{
	renderer_->Draw(renderer);
}

std::string SortProgram::GetSortName(SortType sort) const
{
	return SORTS[(unsigned int) sort]->GetName();
}

void SortProgram::SetMethod(SortType sort)
{
	sort_ = SORTS[(unsigned int)sort];
}

void SortProgram::Join()
{
	if (thread_sort.joinable())
	{
		thread_sort.join();
	}
}

void SortProgram::InitSorts()
{
	SORTS = new ISort*[(unsigned int)SortType::SORTS_COUNT];

	SORTS[(unsigned int)SortType::BUBBLE] = new BubbleSort(arr_info_);
	SORTS[(unsigned int)SortType::MERGE] = new MergeSort(arr_info_);
	SORTS[(unsigned int)SortType::COUNTING] = new CountingSort(arr_info_);
	SORTS[(unsigned int)SortType::SELECTION] = new SelectionSort(arr_info_);
}
