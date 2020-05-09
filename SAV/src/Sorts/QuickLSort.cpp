#include "QuickLSort.h"

#include "Log.h"

extern bool dirtyFlag;

QuickLSort::QuickLSort( Array &array, std::shared_ptr<IDataRenderer> &dataRednderer )
	: ISort( array, dataRednderer ) {
	m_name = "QuickLSort";
	LOG_TRACE( m_name, " has created." );
}

void QuickLSort::Begin()
{
	dirtyFlag = 0;
	QuickLSortBegin(0, m_array.Size() - 1);
	m_dataRenderer->DisplaySorted( );
	LOG_INFO("I am sorted !");
	dirtyFlag = 1;
}

void QuickLSort::QuickLSortBegin(int left, int right)
{
	if (left < right)
	{
		int pivot_index = Partition(left, right);

		QuickLSortBegin(left, pivot_index - 1);
		QuickLSortBegin(pivot_index + 1, right);
	}
}

int QuickLSort::Partition(int left, int right)
{
	m_dataRenderer->RenderIterator( "left", left , 0xc0c0c0 );
	m_dataRenderer->RenderIterator( "right", right, 0x800000 );
	int pivot = m_array[right].Data();
	int i = left - 1;
	for (unsigned int j = left; j < right; j++)
	{
		m_dataRenderer->RenderIterator( "j", j, 0xFFA07A );
		if (m_array[j].Data() < pivot)
		{
			i++;
			m_array[j].Swap( m_array[i] );
		}
	}
	m_dataRenderer->RemoveIterator( "j" );

	i++;
	m_array[right].Swap( m_array[i] );

	m_dataRenderer->RemoveIterator( "left" );
	m_dataRenderer->RemoveIterator( "right" );
	return i;
}
