#pragma once

#include "Data/Array.h"

class IDataController {
public:
    IDataController() = default;
    virtual ~IDataController() = default;

    inline Array & GetData() { return m_array; }

    virtual void Generate(unsigned int size);

    virtual void Shuffle();
protected:
    Array m_array;
};