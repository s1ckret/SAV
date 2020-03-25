#pragma once

#include <array>

#include "Data/Array.h"

class IDataController {
public:
    IDataController() = default;
    virtual ~IDataController() = default;

    Array & GetData() { return m_array; }

    virtual void Generate(unsigned int size, unsigned int max_value);

    virtual void Shuffle();
protected:
    Array m_array;
};