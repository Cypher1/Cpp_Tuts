#include<vector>

#include "stack.hpp"

int main() {
  Stack<int> s1;
  Stack<int, std::deque<int>> s2 = s1;
  Stack<int, std::vector<int>> s3;

  s1.push(1);
  s1.push(2);
  s2 = s1;
//  s3 = s1; // OK? Will look at member templates in Week 8
  std::cout << s1 << s2 << std::endl;
  s1.pop();
  s1.push(3);
  std::cout << s1 << s2 << std::endl;
}
