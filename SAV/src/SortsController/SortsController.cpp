#include "SortsController.h"

SortsController::SortsController()
    : m_dataController(nullptr)
    , m_dataRenderer(nullptr)
{

}

SortsController::~SortsController() {

}

SortsController& SortsController::Get() {
    static SortsController sortsController;
    return sortsController;
}

// TODO: Init Sort
// TODO: Add check for duplicates
// TODO: Template style
// TODO: Get rid of it and replace with an enum
void SortsController::AddSort(ISort * sort) {
    sort->Init(m_dataController, m_dataRenderer);
    m_sortCollection.push_back(std::shared_ptr<ISort>(sort));
}

void SortsController::SetDataRenderer(IDataRenderer * dataRenderer) {
    m_dataRenderer = std::shared_ptr<IDataRenderer>(dataRenderer);
}

void SortsController::SetDataController(IDataController * dataController) {
    m_dataController = std::shared_ptr<IDataController>(dataController);
}

const std::vector<std::shared_ptr<ISort>>& SortsController::GetSortCollection() const {
    return m_sortCollection;
}
