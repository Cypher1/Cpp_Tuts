#include <iostream>
#include <functional>

void f(int a, int b, int c) {
  std::cout << a << " " << b << " " << c << std::endl;
}

int main() {
   auto g1 = std::bind(f, std::placeholders::_1, std::placeholders::_2, 100);
   g1(1, 2); // prints 1 2 100
   auto g2 = std::bind(f, std::placeholders::_2, std::placeholders::_1, 100);
   g2(1, 2); //prints 2 1 100
}
