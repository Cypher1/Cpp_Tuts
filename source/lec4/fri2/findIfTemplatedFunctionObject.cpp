#include <iostream>
#include <vector>
#include <algorithm>

template <class T, T lb, T ub> 
struct range {
  bool operator() (T val) {
    return (lb <= val && val <= ub); 
  }  
};

int main() {
  std::vector<int> vec{ 20, 2, 4, 3, 8, 10, 15, 1};
  
  auto presult = find_if(vec.begin(), vec.end(),
                              range<int, 5, 10>{});

  if (presult == vec.end() )
     std::cout << "[5, 10] not found" << std::endl;
  else
     std::cout << "[5, 10] found" << std::endl;
}
