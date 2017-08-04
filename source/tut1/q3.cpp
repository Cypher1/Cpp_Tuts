#include <fstream>

#include <iostream>

#include "order3.h"

int main() {
  {
    int a, b, c;
    if (!(std::cin >> a >> b >> c))
        throw std::invalid_argument("Not numbers");

    cs6771::order3(&a, &b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';
    
    std::ofstream f{"output.txt"};
    f << a << ' ' << b << ' ' << c << '\n';
  }

  {
    std::ifstream f{"output.txt"};
    unsigned int a, b, c;
    if (!(f >> a >> b >> c))
        throw std::invalid_argument("Not numbers");
    cs6771::order3(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << '\n';
  }
}
