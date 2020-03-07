#pragma once

#include <memory>
#include <vector>

#include "Sorts/ISort.h"
#include "DataController/IDataController.h"
#include "Graphics/DataRenderer/IDataRenderer.h"

class SortsController
{
public:
	static SortsController& Get();

    void AddSort(ISort * sort);
    void SetDataRenderer(IDataRenderer * dataRenderer);
    void SetDataController(IDataController * dataController);

    const std::vector<std::shared_ptr<ISort>>& GetSortCollection() const;

	~SortsController();
private:
	SortsController();

private:
    std::shared_ptr<IDataController> m_dataController;
    std::shared_ptr<IDataRenderer> m_dataRenderer;

    std::vector<std::shared_ptr<ISort>> m_sortCollection;
};