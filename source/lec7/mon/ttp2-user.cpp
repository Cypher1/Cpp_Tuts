#include <vector>
#include "ttpStack.hpp"

int main(void) {
  Stack<int, std::vector > s1;

  s1.push(1);
  s1.push(2);

  std::cout << s1 << std::endl;

}
