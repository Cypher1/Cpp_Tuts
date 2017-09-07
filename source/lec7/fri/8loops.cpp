#include <iostream>

template <unsigned dim, typename T>
struct DotProduct {
  T result(T*, T*) {
    return T{};
  }
};

template <unsigned dim, typename T>
T dotproduct(T*, T*) {
  return T{};
}
 
int main() {
  // extension exercise: implement bubblesort

  int p[3] = {2, 4, 3};
  int q[3] = {1, 5, 2};
  std::cout << dotproduct<3>(p, q);
}
