#include <iostream>

namespace cs6771 {
  void order3(int *a, int *b, int *c) {
    if (*a < *c) {
      int t = *a;
      *a = *c;
      *c = t;
    }
    if (*a < *b) {
      int t = *a;
      *a = *b;
      *b = t;
    }
    if (*b < *c) {
      int t = *b;
      *b = *c;
      *c = t;
    }
  }

}

int main() {
  std::cout << "RUNNING q1!\n";
  return 0;
}
