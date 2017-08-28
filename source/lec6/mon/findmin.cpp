#include <iostream>

template <typename T, int size>
T findmin(const T (&a)[size]) {
  T min = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] < min) min = a[i];
  return min;  
}

// let's write one for iterators next
template <typename It>
auto findmin(It begin, It end) {
  auto min = begin;
  for (; begin != end; ++begin) {
    if (*begin < *min)
      min = begin;
  }
  return min;
}

int main() {
  int x[] = { 3, 1, 2 };
  double y[] = { 3.3, 1.1, 2.2, 4.4};
  double z[] = {1.1, 2.2, 4.4, 5.5};
  std::cout << "min of x = " << findmin(x) << std::endl;
  std::cout << "min of y = " << findmin(y) << std::endl;
  std::cout << "min of y = " << findmin(z) << std::endl;

  
  std::cout << "min of x = " << *findmin(std::cbegin(x), std::cend(x)) << std::endl;
  std::cout << "min of y = " << *findmin(std::cbegin(y), std::cend(y)) << std::endl;
  
}
