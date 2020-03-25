#include "IDataController.h"

#include <random>
#include <algorithm>

void IDataController::Generate(unsigned int size, unsigned int max_value) {
    // TODO: Delete data in array
    m_array.Resize(size);

    for (unsigned int i = 0; i < m_array.Size(); i++) {
        m_array[i] = rand() % max_value;
    }
} 

void IDataController::Shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(m_array.Begin(), m_array.End(), generator);
}