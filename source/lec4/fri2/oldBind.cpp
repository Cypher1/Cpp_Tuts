#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
  std::vector<int> v{ 20, 2, 4, 3, 8, 10, 15, 1};
  
  auto c1 = std::count_if(v.begin(), v.end(), 
                      std::bind1st(std::greater<int>(), 10));
  // SAME AS
  auto c1a = std::count_if(v.begin(), v.end(), 
                      std::bind(std::greater<int>(), 10, std::placeholders::_1));
                      
  auto c2 = std::count_if(v.begin(), v.end(), 
                      std::bind2nd(std::greater<int>(), 10));
  // SAME AS 
  auto c2a = std::count_if(v.begin(), v.end(), 
                      std::bind(std::greater<int>(), std::placeholders::_1, 10));
  std::cout << c1 << ' ' << c1a << '\n';
  std::cout << c2 << ' ' << c2a << '\n';
}
