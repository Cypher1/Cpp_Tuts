#include <iostream>

template <typename T1, typename T2>
void addandprint(T1 t1, T2 t2) {
  std::cout << "in func: " << ++t1 << " " << ++t2 << '\n';
}

int main() {
  int a = 0, b = 100;
  std::cout << "in main: " << a << " " << b << '\n';
  addandprint(a, b);
  std::cout << "in main: " << a << " " << b << '\n';
  addandprint(1, b);
  addandprint(2, 200);
}
