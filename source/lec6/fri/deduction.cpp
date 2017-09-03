#include <iostream>

template <int plus, typename T, int size>
T minplus(const T (&a)[size]) {
  T min = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] < min)
      min = a[i];
  min += plus;
  std::cout << "answer is ";
  std::cout << min;
  return min;
}

template <typename T, typename U>
auto plus(T a, U b) {
  return a + b;
}

int main() {
  std::string x[] = { "ab", "b", "c" };
  // double y[] = { 3.3, 1.1, 2.2, 4.4};
  // double z[] = {1.1, 2.2, 4.4, 5.5};
  std::cout << "min of x = " << minplus<5>(x) << std::endl;
  std::cout << plus(2, static_cast<long>(1)) << '\n';
  /*std::cout << "min of y = " << minplus(y) << std::endl;
  std::cout << "min of y = " << minplus(z) << std::endl;

  
  std::cout << "min of x = " << *minplus(std::cbegin(x), std::cend(x)) << std::endl;
  std::cout << "min of y = " << *minplus(std::cbegin(y), std::cend(y)) << std::endl;
  */
}
