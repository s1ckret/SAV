#include "ISort.h"

ISort::ISort(Array & array, std::shared_ptr<IDataRenderer> & dataRednderer) 
    : m_dataRenderer(dataRednderer)
    , m_array(array)
{
}

void ISort::SetDataRenderer(std::shared_ptr<IDataRenderer> & dataRednderer) {
    m_dataRenderer = dataRednderer;
}

	