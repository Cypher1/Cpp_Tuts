#include <iostream>

template <unsigned u>
struct Factorial {
  static const unsigned val = 0;
};

constexpr unsigned factorial(unsigned n) {
  return n;
}

int main() {
  std::cout << factorial(10) << '\n';
  std::cout << Factorial<10>::val << '\n';
}
