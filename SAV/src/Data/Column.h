#pragma once 

#include "glm/glm.hpp"

struct Column {
public:
    Column() = default;
    ~Column() = default;

    Column & operator=(int rhs);
    bool operator>(const Column & rhs);
    bool operator<(const Column & rhs);
    bool operator>=(const Column & rhs);
    bool operator<=(const Column & rhs);
    
    // Returns !copy! of data
    int Data() const;
private:
    int data;
    glm::vec3 color;
};
