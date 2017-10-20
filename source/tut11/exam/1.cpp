#include <iostream>

int main() {
  int a[] = { 1, 2 };

  int *r = a;
  int **p = &r;
  int *&q = *p;

  q=q+1;
  std::cout << **p << " " << *q << std::endl;
}
