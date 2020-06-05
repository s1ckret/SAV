#include "BubbleSort.h"

#include "Log.h"

extern bool dirtyFlag;

BubbleSort::BubbleSort(std::shared_ptr<IDataController>& dataController,
                       std::shared_ptr<IDataRenderer>& dataRednderer)
    : ISort(dataController, dataRednderer) {
  m_name = "Bubble Sort";
  LOG_TRACE(m_name, " has created.");
}

BubbleSort::~BubbleSort() {
    
}

void BubbleSort::Begin()
{
    dirtyFlag = 0;
    for (unsigned int i = 0; i < m_array.Size(); i++)
    {
        m_dataRndr->RenderIterator("i", i, 0xff0fff);
        for (unsigned int j = 0; j < m_array.Size() - i - 1; j++)
        {
            m_dataRndr->RenderIterator("j", j, 0xff0f00);
            if (m_array[j] > m_array[j + 1])
            {
                std::swap(m_array[j], m_array[j + 1]);
            }
        }
        m_dataRndr->MarkColor(m_array.Size() - i - 1, 0x00ff00);
    }
    m_dataRndr->MarkColor(m_array.Size() - 1, 0x00ff00);

    LOG_INFO("I am sorted !");
    m_dataRndr->DisplaySorted( );
    dirtyFlag = 1;
}
