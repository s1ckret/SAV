#pragma once

#include <memory>

#include "Data/Column.h"
#include "glm/glm.hpp"

class Array {
public:
    Array() = default;
    ~Array() = default;

    void resize(size_t size);

    Column & operator[](size_t index);
    size_t size();

    Column * begin();
    Column * end();
private:
    // In Nodes, not in bytes.
    size_t m_size;
    std::shared_ptr<Column> m_array;

};
