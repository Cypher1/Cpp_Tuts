#include <iostream>
#include <vector>
#include <algorithm>

bool range5to10(int val) { return (5 <= val && val <= 20); }

int main() {
  std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};
  
  auto presult = std::find_if(vec.begin(), vec.end(), range5to10);
  
  if (presult == vec.end() )
     std::cout << "[5, 10] not found" << std::endl;
  else
     std::cout << "[5, 10] found" << std::endl;
}
