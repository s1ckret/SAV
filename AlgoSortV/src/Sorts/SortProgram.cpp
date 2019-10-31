#include "SortProgram.h"


SortProgram::SortProgram()
{
}

SortProgram::~SortProgram()
{
	if (thread_sort.joinable())
	{
		thread_sort.join();
	}
}

void SortProgram::GenerateMassive(unsigned int count)
{
	if (nElements_ != count)
	{
		if (mass_)
		{
			delete[] mass_;
		}
		mass_ = new int[count];
		nElements_ = count;
	}
	for (unsigned int i = 0; i < count; i++)
	{
		mass_[i] = rand() % (2 * count) - count;
	}
}

void SortProgram::Begin()
{
	thread_sort = std::move(std::thread(&ISort::Begin, sort_, std::ref(mass_), nElements_));
}

void SortProgram::Render(const Renderer & renderer)
{
	renderer_->Draw(renderer);
}

void SortProgram::SetMethod(SortType sort)
{
	switch (sort)
	{
	case SortType::BUBBLE: sort_ = new BubbleSort;
		renderer_ = new BubbleSortRenderer(mass_, nElements_);
		break;
	case SortType::MERGE: sort_ = new MergeSort;
		renderer_ = new BubbleSortRenderer(mass_, nElements_);
		break;
	case SortType::QUICK:
		break;
	case SortType::SORTS_COUNT:
		break;
	default:
		break;
	}
}
