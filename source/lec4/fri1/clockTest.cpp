#include <iostream>

#include "Clock.h"


int main() {
  Clock c(1, 2);
  std::cout << c << '\n';
  std::cout << ++c << '\n';
  std::cout << Clock(11, 59) << '\n';
}
