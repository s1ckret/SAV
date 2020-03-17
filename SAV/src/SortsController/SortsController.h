#pragma once

#include <memory>
#include <vector>
#include <thread>

#include "Sorts/ISort.h"
#include "DataController/IDataController.h"
#include "Graphics/DataRenderer/IDataRenderer.h"

class SortsController
{
public:
	static SortsController& Get();

    void AddSort(std::shared_ptr<ISort> sort);

    void SetSort(std::weak_ptr<ISort> sort);

    void BeginSort();

    const std::vector<std::shared_ptr<ISort>>& GetSortCollection() const;

	~SortsController();
private:
	SortsController();
    void Join();

private:
    std::weak_ptr<ISort> m_selectedSort;
    std::vector<std::shared_ptr<ISort>> m_sortCollection;
    std::thread m_thread_sort;
};