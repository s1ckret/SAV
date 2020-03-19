#include "Column.h"

// TODO: lock with mutex. Thread safe
Column & Column::operator=(int rhs) {
    // mutex.lock();
    data = rhs;
    //mutex.unlock();
    return *this;
}

bool Column::operator>(const Column & rhs) {
    return this->data > rhs.data;
}

bool Column::operator<(const Column & rhs) {
    return this->data < rhs.data;
}

bool Column::operator>=(const Column & rhs) {
    return this->data >= rhs.data;
}

bool Column::operator<=(const Column & rhs) {
    return this->data <= rhs.data;
}

// Returns !copy! of data
int Column::Data() const {
    return data;
}