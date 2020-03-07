#include "ISort.h"

void ISort::Init(std::shared_ptr<IDataController> & dataController,
				   std::shared_ptr<IDataRenderer> & dataRednderer) {
    m_dataController = dataController;
    m_dataRenderer = dataRednderer;
}