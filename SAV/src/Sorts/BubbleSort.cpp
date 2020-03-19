#include "BubbleSort.h"

#include "Log.h"

BubbleSort::BubbleSort(Array & array, std::shared_ptr<IDataRenderer> & dataRednderer) 
    : ISort(array, dataRednderer)
{
    m_name = "Bubble Sort";
    LOG_TRACE(m_name, " has created.");
}

BubbleSort::~BubbleSort() {
    
}

void BubbleSort::Begin()
{
	for (unsigned int i = 0; i < m_array.size(); m_dataRenderer->Increment(i))
	{
		for (unsigned int j = 0; j < m_array.size() - i - 1; m_dataRenderer->Increment(j))
		{
			if (m_array[j] > m_array[j + 1])
			{
				m_array[j].Swap(m_array[j + 1]);
			}
		}
	}

	LOG_INFO("I am sorted !");
}
