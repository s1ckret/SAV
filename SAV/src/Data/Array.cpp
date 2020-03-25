#include "Array.h"

#include "Log.h"

void Array::Resize(size_t size) {
    LOG_CRITICAL("Resizing array. Ref count = {0}", m_array.use_count());

    m_size = size;
    std::shared_ptr<Column> new_array(new Column[m_size], std::default_delete<Column[]>());
    m_array.swap(new_array);

    // Is m_array deleted ?
    LOG_CRITICAL("Resizing array. Ref count after swap = {0}", m_array.use_count());
}

Column & Array::operator[](size_t index) {
    return m_array.get()[index];
}

size_t Array::Size() const {
    return m_size;
}

Column * Array::Begin() const {
    Column * beginColumn = nullptr;
    if (m_size) {
        beginColumn = &m_array.get()[0];
    }
    return beginColumn;
}

Column * Array::End() const {
    Column * endColumn = nullptr;
    if (m_size) {
        endColumn = &m_array.get()[m_size - 1];
    }
    endColumn++;
    return endColumn;
}