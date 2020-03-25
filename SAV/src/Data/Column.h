#pragma once 

#include "glm/glm.hpp"

class Column {
public:
    Column();
    ~Column() = default;

    void operator=(int rhs);
    void operator=(glm::vec3 rgbColor);

    bool operator>(const Column & rhs) const;
    bool operator<(const Column & rhs) const;
    bool operator>=(const Column & rhs) const;
    bool operator<=(const Column & rhs) const;
    
    // Only swap data
    void Swap(Column & rhs);

    int Data() const;
    glm::vec3 GetColor() const;
private:
    int m_data;
    glm::vec3 m_color;
};
