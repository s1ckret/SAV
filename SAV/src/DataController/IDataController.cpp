#include "IDataController.h"

#include <random>
#include <algorithm>

void IDataController::Generate(unsigned int size) {
    m_array.Resize(size);

    for (unsigned int i = 0; i < m_array.Size(); i++) {
        m_array[i] = i + 1;
    }
}
bool IDataController::CmpGreater(const int& lhs, const int& rhs) {
  ++m_cmp_count;
  return lhs > rhs;
}

bool IDataController::CmpLess(const int& lhs, const int& rhs) {
  ++m_cmp_count;
  return lhs < rhs;
}

bool IDataController::CmpEqual(const int& lhs, const int& rhs) {
  ++m_cmp_count;
  return lhs == rhs;
}

void IDataController::Swap(int& lhs, int& rhs) {
  ++m_swap_count;
  std::swap(lhs, rhs);
}

void IDataController::Assign(int& lhs, const int& rhs) {
  ++m_assignment_count;
  lhs = rhs;
}
 

void IDataController::Shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(m_array.begin().GetElem(), m_array.end().GetElem(), generator);
}

void IDataController::ResetCounters() {
  m_cmp_count = 0;
  m_swap_count = 0;
  m_assignment_count = 0;
}

unsigned IDataController::GetCmpCount() const { return m_cmp_count; }

unsigned IDataController::GetSwapCount() const { return m_swap_count; }

unsigned IDataController::GetAssignmentCount() const { return m_assignment_count; }
