#pragma once

#include <array>

#include "Data/Array.h"

class IDataController {
public:
    IDataController() = default;
    virtual ~IDataController() = default;

    Array & GetData() { return m_array; }

    virtual void Generate(unsigned int size, unsigned int max_value) = 0;

    virtual void Shuffle() = 0;
protected:
    Array m_array;

};