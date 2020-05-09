#include "SortsController.h"

#include "Log.h"

SortsController::~SortsController() {
    Join();
}

SortsController& SortsController::Get() {
    static SortsController sortsController;
    return sortsController;
}

void SortsController::AddSort(std::shared_ptr<ISort> sort) {
    m_sortCollection.push_back(sort);
}

void SortsController::SetSort(std::weak_ptr<ISort> sort) {
    m_selectedSort = sort;
}

void SortsController::BeginSort() {
    Join();
    if (auto sort = m_selectedSort.lock()) {
        m_thread_sort = std::move(std::thread(&ISort::Begin, std::ref(*sort.get())));
    }
    else {
        LOG_WARN("Weak pointer is expired!");
    }
    
}

const std::vector<std::shared_ptr<ISort>>& SortsController::GetSortCollection() const {
    return m_sortCollection;
}

void SortsController::Join()
{
	if (m_thread_sort.joinable())
	{
		m_thread_sort.join();
	}
}