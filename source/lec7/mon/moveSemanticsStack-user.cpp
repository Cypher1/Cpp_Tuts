#include <string>
#include "memberTemplatesStack.hpp"

int main() {
  double a[] = {1.1, 2.2, 3.3};
  Stack<double> fs(a, a+3);

  Stack<int> is = std::move(fs);
  std::cout << "is: " << is << "fs: " << fs << std::endl;

  fs = std::move(is);
  std::cout << "is: " << is << "fs: " << fs << std::endl;
}
