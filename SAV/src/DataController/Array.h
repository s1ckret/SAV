#pragma once

#include <memory>

#include "glm/glm.hpp"

struct Node {
public:
    // TODO: lock with mutex. Thread safe
    // TODO: operator=()
    inline Node & operator=(int rhs) {
        // mutex.lock();
        data = rhs;
        //mutex.unlock();
        return *this;
    }

    inline bool operator>(const Node & rhs) {
        return this->data > rhs.data;
    }

    inline bool operator<(const Node & rhs) {
        return this->data < rhs.data;
    }

    inline bool operator>=(const Node & rhs) {
        return this->data >= rhs.data;
    }

    inline bool operator<=(const Node & rhs) {
        return this->data <= rhs.data;
    }
    
    // Returns !copy! of data
    inline int Data() const {
        return data;
    }
private:
    int data;
    glm::vec3 color;
};

class Array {
public:
    Array() = default;
    ~Array() = default;

    void resize(size_t size);

    Node & operator[](size_t index);
    size_t size();

    Node * begin();
    Node * end();
private:
    // In Nodes, not in bytes.
    size_t m_size;
    std::shared_ptr<Node> m_array;

};
