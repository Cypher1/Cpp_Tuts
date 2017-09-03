#include <iostream>

#include "stack.hpp"

int main() {
  Stack<int> s1; // int: template argument
  s1.push(1);
  s1.push(2);
  Stack<int> s2 = s1;
  std::cout << s1 << s2 << std::endl;
  s1.pop();
  s1.push(3);
  std::cout << s1 << s2 << std::endl;
}
