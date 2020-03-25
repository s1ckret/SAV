#include "Column.h"

Column::Column() 
    : m_data(0)
    , m_color({1.f, 1.f, 1.f})
{
}

// TODO: lock with mutex. Thread safe
void Column::operator=(int rhs) {
    // mutex.lock();
    m_data = rhs;
    //mutex.unlock();
}

void Column::operator=(glm::vec3 rgbColor) {
    m_color = rgbColor;
}

bool Column::operator>(const Column & rhs) const {
    return this->m_data > rhs.m_data;
}

bool Column::operator<(const Column & rhs) const {
    return this->m_data < rhs.m_data;
}

bool Column::operator>=(const Column & rhs) const {
    return this->m_data >= rhs.m_data;
}

bool Column::operator<=(const Column & rhs) const {
    return this->m_data <= rhs.m_data;
}

// TODO: lock with mutex. Thread safe
void Column::Swap(Column & rhs) {
    // mutex.lock
    int tmp = this->m_data;
    this->m_data = rhs.m_data;
    rhs.m_data = tmp;
    // mutex.unlock
}

// Returns !copy! of m_data
int Column::Data() const {
    return m_data;
}

glm::vec3 Column::GetColor() const {
    return m_color;
}