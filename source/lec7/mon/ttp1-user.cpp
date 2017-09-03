#include <iostream>
#include <vector>
#include "memberTemplatesStack.hpp"

int main(void) {
  Stack<int, std::vector<int>> s1;
  s1.push(1);
  s1.push(2);
  std::cout << "s1: " << s1 << std::endl;

  Stack<double, std::vector<int>> s2;
  // the compiler will throw an error at me here because I try to convert it from a double to an int. I think it only throws the error because I have -wpedantic on. You should too!
  // s2.push(1.1);
  // s2.push(2.2);
  std::cout << "s2: " << s2 << std::endl;

  Stack<int, std::vector<double>> s3;
  // s3.push(1.1);
  // s3.push(2.2);
  std::cout << "s3: " << s3 << std::endl;
}
