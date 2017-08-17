#include <iostream>
#include <vector>
#include <algorithm>

class range {
public:
  range(int l, int u) : lb(l), ub(u) { }
  bool operator() (int val) {
     return (lb <= val && val <= ub); 
  }  
private:
  int lb, ub;
};

int main() {
  std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};
  
  auto presult = std::find_if(vec.begin(), vec.end(),
                                range{5,10});
  
  if (presult == vec.end() )
     std::cout << "[5, 10] not found" << std::endl;
  else
     std::cout << "[5, 10] found" << std::endl;
}
