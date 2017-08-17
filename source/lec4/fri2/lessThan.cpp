#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  int a[8] = { 20, 2, 4, 3, 8, 10, 15, 1 };
  std::vector<int> vec(a, a + 8);
  
  std::sort(vec.begin(), vec.end());

  std::copy(vec.begin(), vec.end(),
            std::ostream_iterator<int>(std::cout, " "));
}
