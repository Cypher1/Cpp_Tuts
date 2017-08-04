#include <fstream>
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
  int a, b, c;
  if (!(std::cin >> a >> b >> c))
    throw std::invalid_argument("Not numbers");

  cs6771::order3(&a, &b, &c);
  std::cout << a << ' ' << b << ' ' << c << '\n';
  
  std::ofstream f{"output.txt"};
  f << a << ' ' << b << ' ' << c << '\n';
  return 0;
}
