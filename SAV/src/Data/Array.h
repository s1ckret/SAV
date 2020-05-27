#pragma once

#include <GLM/glm.hpp>
#include <memory>

struct Column {
 public:
  Column();
  bool operator==(Column& rhs);
  bool operator!=(Column& rhs);

  friend class Array;
  friend void SetColor(Array* arr, size_t index, unsigned hex);
  friend void SetColor(Array* arr, size_t index, glm::vec3 rgb);
  friend glm::vec3 GetColor(Array* arr, size_t index);
 private:
  int m_data;
  glm::vec3 m_color;
};

class Array {
 public:
  Array();
  ~Array() = default;

  void Resize(size_t size);

  int& operator[](size_t index) const;
  size_t Size() const;
  int GetMaxValue() const;

  class iterator;
  iterator begin();
  const iterator begin() const;
  iterator end();
  const iterator end() const;
  const iterator cbegin() const;
  const iterator cend() const;

  friend void SetColor(Array* arr, size_t index, unsigned hex);
  friend void SetColor(Array* arr, size_t index, glm::vec3 rgb);
  friend glm::vec3 GetColor(Array* arr, size_t index);
 private:
  size_t m_size;
  std::shared_ptr<Column> m_array;
};

class Array::iterator {
 public:
  iterator(Column* p);

  iterator& operator++();
  iterator operator++(int);
  iterator& operator--();
  iterator operator--(int);
  Column* GetElem() const;
  int& operator*();

  bool operator==(const Array::iterator& rhs);
  bool operator!=(const Array::iterator& rhs);

 private:
  Column* m_curr;
};

void SetColor(Array* arr, size_t index, unsigned hex);
void SetColor(Array* arr, size_t index, glm::vec3 rgb);
glm::vec3 GetColor(Array* arr, size_t index);