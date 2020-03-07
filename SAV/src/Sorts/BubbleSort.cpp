#include "BubbleSort.h"

#include "Log.h"

BubbleSort::BubbleSort() 
    : ISort()
{
    m_name = "Bubble Sort";
    LOG_TRACE(m_name, " has created.");
}

BubbleSort::~BubbleSort() {
    
}

void BubbleSort::Begin()
{
    Data& array = m_dataController->GetData();
	for (unsigned int i = 0; i < array.size(); m_dataRenderer->Increment(i))
	{
		for (unsigned int j = 0; j < array.size() - i - 1; m_dataRenderer->Increment(j))
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}

	LOG_INFO("I am sorted !");
}
