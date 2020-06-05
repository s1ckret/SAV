#include "QuickLSort.h"

#include "Log.h"

extern bool dirtyFlag;

QuickLSort::QuickLSort(std::shared_ptr<IDataController>& dataController,
                       std::shared_ptr<IDataRenderer>& dataRednderer)
    : ISort(dataController, dataRednderer) {
	m_name = "QuickLSort";
	LOG_TRACE( m_name, " has created." );
}

void QuickLSort::Begin()
{
	QuickLSortBegin(0, m_array.Size() - 1);
	m_dataRndr->DisplaySorted( );
	LOG_INFO("I am sorted !");
}

void QuickLSort::QuickLSortBegin(int left, int right)
{
	if (m_dataCtrl->CmpLess(left, right))
	{
		int pivot_index = Partition(left, right);

		QuickLSortBegin(left, pivot_index - 1);
		QuickLSortBegin(pivot_index + 1, right);
	}
}

int QuickLSort::Partition(int left, int right)
{
	m_dataRndr->RenderIterator( "left", left , 0xc0c0c0 );
	m_dataRndr->RenderIterator( "right", right, 0x800000 );
	int pivot = m_array[right];
	int i = left - 1;
	for (unsigned int j = left; j < right; j++)
	{
		m_dataRndr->RenderIterator( "j", j, 0xFFA07A );
        if (m_dataCtrl->CmpLess(m_array[j], pivot))
		{
			i++;
			m_dataCtrl->Swap(m_array[j], m_array[i]);
		}
	}
	m_dataRndr->RemoveIterator( "j" );

	i++;
    m_dataCtrl->Swap(m_array[right], m_array[i]);

	m_dataRndr->RemoveIterator( "left" );
	m_dataRndr->RemoveIterator( "right" );
	return i;
}
