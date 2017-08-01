#include <iostream>

namespace cs6771 {
  void order3(unsigned int& a, unsigned int& b, unsigned int& c) {
    if (a > c) {
      int t = a;
      a = c;
      c = t;
    }
    if (b > c) {
      int t = b;
      b = c;
      c = t;
    }
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
  }
}

int main() {
  std::cout << "RUNNING q2!\n";
  return 0;
}
