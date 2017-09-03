#include "memberTemplatesStack.hpp"

int main() {
  double a[] = {1.1, 2.2, 3.3}; 
  Stack<double> fs(a, a+3);  
  // instantiate Stack<float, deque<float>>(float*, float*)

  fs.assign(a, a+3);
  // Stack<float, deque<float>>::assign(float *, float*);
  std::cout << fs << std::endl;

  Stack<int> is = fs; 
  // Stack<int, deque<int>>(const Stack<float, deque<float>> &)
  std::cout << is << fs << std::endl;

  is = fs;
  // Stack<int, deque<int>>::operator=(const Stack<float, deque<float>> &)
  std::cout << is << fs << std::endl;
}
