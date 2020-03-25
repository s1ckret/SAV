#pragma once

#include <memory>

#include "Data/Column.h"
#include "glm/glm.hpp"

class Array {
public:
    Array() = default;
    ~Array() = default;

    void Resize(size_t size);

    Column & operator[](size_t index);
    size_t Size() const;

    Column * Begin() const;
    Column * End() const;
private:
    size_t m_size;
    std::shared_ptr<Column> m_array;

};
