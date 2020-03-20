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
	for (unsigned int i = 0; i < m_array.size(); m_dataRenderer->Increment("i", i, 0xff0fff))
	{
		for (unsigned int j = 0; j < m_array.size() - i - 1; m_dataRenderer->Increment("j", j, 0xff000f))
		{
			if (m_array[j] > m_array[j + 1])
			{
				m_array[j].Swap(m_array[j + 1]);
			}
		}
		m_dataRenderer->MarkDefaultColor(m_array.size() - i - 1, 0x00ff00);
	}
	m_dataRenderer->MarkColor(m_array.size() - 1, 0x00ff00);

	LOG_INFO("I am sorted !");
}
