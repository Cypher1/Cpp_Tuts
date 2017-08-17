#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "SmallInt.h"

int main() {
  std::vector<SmallInt> vec{SmallInt{3}, SmallInt{1}, SmallInt{2}};
  
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), 
       std::ostream_iterator<SmallInt>(std::cout, " "));
}
