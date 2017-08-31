#include <iostream>
#include <memory>

template <typename T>
void print(const T& msg) {
  std::cout << msg << " ";
}

// this is actually bad practice. We'll talk about perfect forwarding next week
template <typename A, typename... B>
void print(A head, B... tail) {
  print(head);
  print(tail...);
}

int main() {
  print(1, 2.0f);
  std::cout << '\n';
  print(1, 2.0f, "Hello");
  std::cout << '\n';
}
