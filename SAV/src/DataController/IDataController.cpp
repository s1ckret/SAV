#include "IDataController.h"

#include <random>
#include <algorithm>

void IDataController::Generate(unsigned int size, unsigned int max_value) {
    m_array.Resize(size);

    for (unsigned int i = 0; i < m_array.Size(); i++) {
        m_array[i] = i + 1;
    }
} 

void IDataController::Shuffle() {
	for ( unsigned int i = 0; i < m_array.Size(); i++ ) {
		unsigned int randomIndex = rand( ) % m_array.Size( );
		int temp = m_array[i].Data();
		m_array[i] = m_array[randomIndex].Data();
		m_array[randomIndex] = temp;

	}
}