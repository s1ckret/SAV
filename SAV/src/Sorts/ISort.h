#pragma once 

#include <memory>
#include <string>

#include "Graphics/DataRenderer/IDataRenderer.h"
#include "Data/Array.h"
#include "DataController/IDataController.h"

class ISort {
 public:
  ISort(std::shared_ptr<IDataController>& dataController,
        std::shared_ptr<IDataRenderer>& dataRednderer);
  virtual ~ISort() = default;

  void SetDataRenderer(std::shared_ptr<IDataRenderer>& dataRednderer);

  void SetDataController(std::shared_ptr<IDataController>& dataController);

  virtual void Begin() = 0;

  inline std::string GetName() const { return m_name; }

 protected:
  std::shared_ptr<IDataController> m_dataCtrl;
  std::shared_ptr<IDataRenderer> m_dataRndr;
  Array& m_array;
  std::string m_name;
};
