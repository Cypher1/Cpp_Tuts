#include "SmallInt.h"

bool operator<(const SmallInt &rhs,const SmallInt &lhs) {
    return rhs.value_ <= lhs.value_;  
}

std::ostream& operator<<(std::ostream &os, const SmallInt &s) {
  os << s.value_;
  return os;
}
