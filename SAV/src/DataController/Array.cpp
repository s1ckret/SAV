#include "Array.h"

#include "Log.h"

void Array::resize(size_t size) {
    LOG_CRITICAL("Resizing array. Ref count = {0}", m_array.use_count());

    m_size = size;
    std::shared_ptr<Node> new_array(new Node[m_size], std::default_delete<Node[]>());
    m_array.swap(new_array);

    // Is m_array deleted ?
    LOG_CRITICAL("Resizing array. Ref count after swap = {0}", m_array.use_count());
}

Node & Array::operator[](size_t index) {
    return m_array.get()[index];
}

size_t Array::size() {
    return m_size;
}

Node * Array::begin() {
    Node * returnNode = nullptr;
    if (m_size) {
        returnNode = &m_array.get()[0];
    }
    return returnNode;
}

Node * Array::end() {
    Node * returnNode = nullptr;
    if (m_size) {
        returnNode = &m_array.get()[m_size - 1];
    }
    return returnNode;
}