#pragma once 

#include "glm/glm.hpp"

class Column {
public:
    Column();
    ~Column() = default;

    void operator=(int rhs);
    void operator=(glm::vec3 rgbColor);

    bool operator>(const Column & rhs);
    bool operator<(const Column & rhs);
    bool operator>=(const Column & rhs);
    bool operator<=(const Column & rhs);
    
    // Only swap data
    void Swap(Column & rhs);

    // Returns !copy! of data
    int Data() const;
private:
    int m_data;
    glm::vec3 m_color;
};
