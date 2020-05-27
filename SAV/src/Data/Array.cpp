#include "Array.h"

#include "Log.h"
#include "Utility.h"

Array::Array( )
    : m_size(0)
{ }

void Array::Resize(size_t size) {
    m_size = size;
    std::shared_ptr<Column> new_array(new Column[m_size], [](Column * ptr) {
        LOG_INFO("Delete[] from lamda");
        delete[] ptr;
    });
    m_array.swap(new_array);
}

int& Array::operator[](size_t index) const {
    return m_array.get()[index].m_data;
}

size_t Array::Size() const {
    return m_size;
}

int Array::GetMaxValue() const {
  int max = (*this)[0];
  for (auto it = this->begin(); it != this->end(); it++) {
    if (*it > max) {
      max = *it;
    }
  }
  return max;
}

Array::iterator Array::begin() { 
  return Array::iterator(&m_array.get()[0]); 
}

const Array::iterator Array::begin() const {
  return Array::iterator(&m_array.get()[0]);
}

Array::iterator Array::end() { 
  return Array::iterator(&m_array.get()[m_size]); 
}

const Array::iterator Array::end() const {
  return Array::iterator(&m_array.get()[m_size]);
}

const Array::iterator Array::cbegin() const {
  return Array::iterator(&m_array.get()[0]);
}

const Array::iterator Array::cend() const {
  return Array::iterator(&m_array.get()[m_size]);
}

Array::iterator::iterator(Column* p) : m_curr(p) {}

Array::iterator& Array::iterator::operator++() {
  m_curr++;
  return *this;
}

Array::iterator Array::iterator::operator++(int) {
  Array::iterator temp = m_curr;
  m_curr++;
  return temp;
}

Array::iterator& Array::iterator::operator--() {
  m_curr--;
  return *this;
}

Array::iterator Array::iterator::operator--(int) {
  Array::iterator temp = m_curr;
  m_curr--;
  return temp;
}

Column* Array::iterator::GetElem() const { return m_curr; }

int& Array::iterator::operator*() { return m_curr->m_data; }

bool Array::iterator::operator==(const iterator& rhs) {
  return *m_curr == *rhs.m_curr;
}

bool Array::iterator::operator!=(const iterator& rhs) {
  return *m_curr != *(rhs.m_curr);
}

Column::Column()
    : m_data(0) 
    , m_color(1.f, 1.f, 1.f) {}

bool Column::operator==(Column& rhs) { return m_data == rhs.m_data; }

bool Column::operator!=(Column& rhs) { return m_data != rhs.m_data; }

void SetColor(Array * arr, size_t index, unsigned hex) {
  arr->m_array.get()[index].m_color = ToRGB(hex);
}

void SetColor(Array* arr, size_t index, glm::vec3 rgb) {
  arr->m_array.get()[index].m_color = rgb;
}

glm::vec3 GetColor(Array* arr, size_t index) {
  return arr->m_array.get()[index].m_color;
}
