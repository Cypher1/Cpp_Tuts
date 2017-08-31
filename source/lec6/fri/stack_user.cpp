#include <iostream>

#include "stack.h"

int main() {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);

  Stack<int> s2 = s1;
  std::cout << s1 << '\n' << s2 << '\n';
  s1.pop();
  s1.push(3);
  std::cout << s1 << '\n' << s2 << '\n';
}
