#include "Sandbox.h"

#include "DataController/BasicDataController.h"
#include "DataRenderer/BasicDataRenderer.h"

#include "Sorts/BubbleSort.h"
#include "Sorts/CountingSort.h"
#include "Sorts/MergeSort.h"
#include "Sorts/QuickLSort.h"

Sandbox::Sandbox() 
    : App() {}

Sandbox::~Sandbox() {}

void Sandbox::InitUser() {
  m_dataCtrl = std::make_shared<BasicDataController>();
  m_dataCtrl->Generate(m_arraySize);
  m_dataRndr = std::make_shared<BasicDataRenderer>(&m_dataCtrl->GetData(), m_arraySize);
  SortsController::Get().AddSort(
      std::make_shared<BubbleSort>(m_dataCtrl->GetData(), m_dataRndr));
  SortsController::Get().AddSort(
      std::make_shared<CountingSort>(m_dataCtrl->GetData(), m_dataRndr));
  SortsController::Get().AddSort(
      std::make_shared<QuickLSort>(m_dataCtrl->GetData(), m_dataRndr));
  SortsController::Get().AddSort(
      std::make_shared<MergeSort>(m_dataCtrl->GetData(), m_dataRndr));
}

App* CreateApp() { return new Sandbox; }
