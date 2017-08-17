#include<iostream>
#include<cassert>
#include "SafeArray.h"

int main() {
  SafeArray s{10};
  s[12] = 2;
  std::cout << s[2] << std::endl;
}
