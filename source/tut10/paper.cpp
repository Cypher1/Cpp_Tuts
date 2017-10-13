#include<iostream>
#include<typeinfo>
#include<utility>

void e(const int&, int, int) {
  std::cout << "const ref (1)\n";
}

void e(int& a, int, int) {
  a++;
  std::cout << "non const ref (2)\n";
}

template <typename A, typename B, typename C>
void func(A &&a, B &&b, C &&c) {
  // always call std::forward, never forward
  e(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c));
}

int k{4};
int global() {
  return k;
}

int main() {
  func(1, 2, 3);
  int i{1};
  func(i, 2, 3);
  const int &j = i;
  func(j, 2, 3);
  func(global(), 2, 3);

  std::cout << " K = " << global() << std::endl;
}
