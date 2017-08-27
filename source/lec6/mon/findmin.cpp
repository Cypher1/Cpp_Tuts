#include <iostream>

template <typename T, int size>
T findmin(const T (&a)[size]) {
  T min = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] < min) min = a[i];
  return min;  
}

// let's write one for iterators next

int main() {
  int x[] = { 3, 1, 2 };
  double y[] = { 3.3, 1.1, 2.2, 4.4};
  std::cout << "min of x = " << findmin(x) << std::endl;
  std::cout << "min of y = " << findmin(y) << std::endl;

  /*
  std::cout << "min of x = " << *findmin(x.begin(), x.end()) << std::endl;
  std::cout << "min of y = " << *findmin(y.begin(), y.end()) << std::endl;
  */
}
