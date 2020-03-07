#pragma once

#include <vector>

using Data = std::vector<int>;

class IDataController {
public:
    IDataController() = default;
    virtual ~IDataController() = default;

    inline Data& GetData() { return m_array; }

    virtual void Generate(unsigned int size, unsigned int max_value) = 0;

    virtual void Shuffle() = 0;
protected:
    Data m_array;

};