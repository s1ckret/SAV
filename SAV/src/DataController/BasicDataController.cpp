#include "BasicDataController.h"

#include <random>
#include <algorithm>

BasicDataController::BasicDataController() 
    : IDataController()
{

}

BasicDataController::~BasicDataController() {

}

void BasicDataController::Generate(unsigned int size, unsigned int max_value) {
    // Delete data in array
    Data().swap(m_array);
    
    m_array.resize(size);
    for (unsigned int i = 0; i < m_array.size(); i++) {
        m_array[i] = rand() % max_value;
    }
} 

void BasicDataController::Shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(m_array.begin(), m_array.end(), generator);
}