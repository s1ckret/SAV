#include "SortProgram.h"

ISort* SortProgram::SORTS[(unsigned int)SortType::SORTS_COUNT] = 
{ 
	new BubbleSort,
	new MergeSort
};

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

SortProgram & SortProgram::Get()
{
	static SortProgram sortProgram;
	return sortProgram;
}

void SortProgram::GenerateMassive(const unsigned int nElements, const int max_value)
{
	max_value_ = max_value;
	if (nElements_ != nElements)
	{
		nElements_ = nElements;
		if (mass_)
		{
			free(mass_);
			free(color_markers_);
		}
		mass_ = (int*)malloc(sizeof(int) * nElements_);
		color_markers_ = (Vec3*)malloc(sizeof(Vec3) * nElements_);
	}
	for (unsigned int i = 0; i < nElements_; i++)
	{
		mass_[i] = rand() % max_value_;
	}
	ShuffleMassive();
}

void SortProgram::Begin()
{
	Join();
	thread_sort = std::move(std::thread(&ISort::Begin, sort_, std::ref(mass_), nElements_, std::ref(color_markers_)));
}

void SortProgram::ShuffleMassive()
{
	for (unsigned int i = 0; i < nElements_; i++)
	{
		unsigned int randomIndex = rand() % nElements_;
		int temp = mass_[i];
		mass_[i] = mass_[randomIndex];
		mass_[randomIndex] = temp;

		color_markers_[i].Set(1.f, 1.f, 1.f);
	}
}

void SortProgram::Render(const Renderer & renderer)
{
	renderer_->Draw(renderer);
}

void SortProgram::SetMethod(SortType sort)
{
	sort_ = SORTS[(unsigned int)sort];
	if (!renderer_)
	{
		renderer_ = new SortRenderer(mass_, color_markers_, nElements_, max_value_);
	}
}

void SortProgram::Join()
{
	if (thread_sort.joinable())
	{
		thread_sort.join();
	}
}