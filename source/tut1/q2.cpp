#include <fstream>
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
  std::ifstream f{"output.txt"};
  unsigned int a, b, c;
  if (!(f >> a >> b >> c))
    throw std::invalid_argument("Not numbers");
  cs6771::order3(a, b, c);

  std::cout << a << ' ' << b << ' ' << c << '\n';
  return 0;
}
