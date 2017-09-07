#include <iostream>

template <unsigned n>
struct Fib {
  static const unsigned val = 0;
};

constexpr unsigned fib(unsigned n) {
  return n;
}

template <unsigned n>
struct Identity {
  static const unsigned val = n;
};

int main() {
  std::cout << Fib<10>::val << '\n';
  std::cout << fib(10) << '\n';

  std::cout << Fib<100>::val << '\n';
  std::cout << Identity<fib(100)>::val << '\n';
  std::cout << fib(100) << '\n';

  /*
  for (auto i = 0U; i < 10; ++i) {
    std::cout << fib(i) << '\n';
    std::cout << Fib<i> << '\n';
  }
  */
}
