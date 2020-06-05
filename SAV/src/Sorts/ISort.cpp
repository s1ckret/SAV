#include "ISort.h"

ISort::ISort(std::shared_ptr<IDataController>& dataController,
             std::shared_ptr<IDataRenderer>& dataRednderer)
    : m_dataCtrl(dataController)
    , m_dataRndr(dataRednderer)
    , m_array(m_dataCtrl->GetData()) {}

void ISort::SetDataRenderer(std::shared_ptr<IDataRenderer>& dataRednderer) {
  m_dataRndr = dataRednderer;
}

void ISort::SetDataController(
    std::shared_ptr<IDataController>& dataController) {
  m_dataCtrl = dataController;
  m_array = m_dataCtrl->GetData();
}

	