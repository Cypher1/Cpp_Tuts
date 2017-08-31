#include <iostream>

template <typename T, int size, int plus>
T minplus(const T (&a)[size]) {
  T min = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] < min) min = a[i];
  min += plus;
  return min;
}

int main() {
  int x[] = { 3, 1, 2 };
  // double y[] = { 3.3, 1.1, 2.2, 4.4};
  // double z[] = {1.1, 2.2, 4.4, 5.5};
  std::cout << "min of x = " << minplus<int, 3, 5>(x) << std::endl;
  /*std::cout << "min of y = " << minplus(y) << std::endl;
  std::cout << "min of y = " << minplus(z) << std::endl;

  
  std::cout << "min of x = " << *minplus(std::cbegin(x), std::cend(x)) << std::endl;
  std::cout << "min of y = " << *minplus(std::cbegin(y), std::cend(y)) << std::endl;
  */
}
