#include "MergeSort.h"

#include "Log.h"

extern bool dirtyFlag;

MergeSort::MergeSort(std::shared_ptr<IDataController> &dataController,
                     std::shared_ptr<IDataRenderer> &dataRednderer)
    : ISort(dataController, dataRednderer) {
	m_name = "Merge Sort";
	LOG_TRACE( m_name, " has created." );
}

void MergeSort::Begin()
{
	dirtyFlag = 0;
	MergeSortBegin(0, m_array.Size() - 1);
	m_dataRndr->DisplaySorted( );
	LOG_INFO("I am sorted !");
	dirtyFlag = 1;
}

void MergeSort::MergeSortBegin(unsigned int left, unsigned int right)
{
	if (m_dataCtrl->CmpLess(left, right))
	{
		unsigned int mid = (left + right) / 2;

		MergeSortBegin(left, mid);
		MergeSortBegin(mid + 1, right);

		Merge(left, mid, right);
	}
}

void MergeSort::Merge(unsigned int left, unsigned int mid, unsigned int right)
{
	// Finding arrays size
	unsigned int sizeLeft = mid - left + 1;
	unsigned int sizeRight = right - mid;
	// Createing temporaly arrays
	int *tempLeft = new int [sizeLeft];
	int *tempRight = new int[sizeRight];
	LOG_TRACE( "Copying into left auxillary array..." );
	// Copy data into Left array
	for (unsigned int i = 0; i < sizeLeft; i++) 
	{
		m_dataRndr->RenderIterator( "i", left + i, 0xff0000 );
		tempLeft[i] = m_array[left + i];
	}
	LOG_TRACE( "Copying into right auxillary array..." );
	// Copy data into Right array
	for (unsigned int i = 0; i < sizeRight; i++) 
	{
		m_dataRndr->RenderIterator( "i", mid + i + 1, 0x0000ff );
		tempRight[i] = m_array[mid + i + 1];
	}
	m_dataRndr->RemoveIterator( "i" );
	LOG_TRACE( "Merging..." );
	// Merging
	unsigned int i = 0, j = 0, k = left;
	while (i < sizeLeft && j < sizeRight)
	{
		m_dataRndr->RenderIterator( "i", left + i, 0xff0000 );
		m_dataRndr->RenderIterator( "j", mid + i + 1, 0x0000ff );

		if (m_dataCtrl->CmpLess(tempLeft[i], tempRight[j]))
		{
			m_array[k] = tempLeft[i];
			i++;
		}
		else
		{
			m_array[k] = tempRight[j];
			j++;
		}
		k++;
	}
	LOG_TRACE( "Copying the remaining elements from left auxillary array..." );
	// Copy the remaining elements
	while (i < sizeLeft)
	{
		m_dataRndr->RenderIterator( "i", left + i, 0xff0000 );
		m_array[k] = tempLeft[i];
		i++;
		k++;
	}
	LOG_TRACE( "Copying the remaining elements from right auxillary array..." );
	// Copy the remaining elements 
	while (j < sizeRight)
	{
		m_dataRndr->RenderIterator( "j", mid + i, 0x0000ff );
		m_array[k] = tempRight[j];
		j++;
		k++;
	}
	m_dataRndr->RemoveIterator( "i" );
	m_dataRndr->RemoveIterator( "j" );

	delete[] tempLeft;
	delete[] tempRight;
}
