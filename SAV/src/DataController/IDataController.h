#pragma once

#include "Data/Array.h"

class IDataController {
 public:
  IDataController() = default;
  virtual ~IDataController() = default;

  inline Array &GetData() { return m_array; }

  virtual void Generate(unsigned int size);

  // Lhs > Rhs
  virtual bool CmpGreater(const int &lhs, const int &rhs);
  // Lhs < Rhs
  virtual bool CmpLess(const int &lhs, const int &rhs);
  // Lhs == Rhs
  virtual bool CmpEqual(const int &lhs, const int &rhs);

  virtual void Swap(int &lhs, int &rhs);

  virtual void Shuffle();

  void ResetCounters();

  unsigned GetCmpCount() const;
  unsigned GetSwapCount() const;

 protected:
  Array m_array;
  unsigned m_cmp_count;
  unsigned m_swap_count;
};