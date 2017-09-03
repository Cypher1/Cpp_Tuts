#include <deque>
#include <iostream>

#include "stack.h"

int main() {
  Stack<double, std::deque<double>> s1;
  Stack<double, std::vector<double>> s3;
  s1.push(1);
  s1.push(2);

  auto s2 = s1;
  Stack<int> s4;
  Stack<int> s5;
  std::cout << s1 << '\n' << s2 << '\n';
  s1.pop();
  s1.push(3);
  std::cout << s1 << '\n' << s2 << '\n';
  auto s6 = std::move(s1);
}

