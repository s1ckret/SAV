#include "BasicDataController.h"

#include <random>
#include <algorithm>

#include "Log.h"

BasicDataController::BasicDataController() 
    : IDataController()
{

}

BasicDataController::~BasicDataController() {

}

void BasicDataController::Generate(unsigned int size, unsigned int max_value) {
    // Delete data in array
    
    m_array.Resize(size);

    for (unsigned int i = 0; i < m_array.Size(); i++) {
        m_array[i] = rand() % max_value;
    }
} 

void BasicDataController::Shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());

    LOG_CRITICAL("SHUFFLING!");
    // TOTEST:
    std::shuffle(m_array.Begin(), m_array.End(), generator);
}