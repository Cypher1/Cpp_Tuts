#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class range {
public:
  bool operator() (int lb, int ub, int val) {
     return (lb <= val && val <= ub); 
  }  
};

int main() {
  std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};
  
  auto presult = std::find_if(vec.begin(), vec.end(),
                                std::bind(range{},5,10,std::placeholders::_1));
  
  if (presult == vec.end() )
     std::cout << "[5, 10] not found" << std::endl;
  else
     std::cout << "[5, 10] found" << std::endl;
}
