#include <iostream>
#include "UB_stack.h"

int main() {
  UB_stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  std::cout << s.top() << std::endl;
  // ...
}
