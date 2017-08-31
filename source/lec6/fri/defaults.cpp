#include <iostream>
#include <functional>

template <typename T, typename Pred=std::less<T>>
T minTD(T a, T b, Pred cmp = Pred()) {
    return cmp(a, b) ? a : b; 
}

bool cmpstr(std::string a, std::string b) {
  return a.size() < b.size();
}

int main() {
  std::cout << minTD(1,2) << std::endl;
  std::string s1 = "xyz";
  std::string s2 = "abcd";
  std::cout << minTD(s1, s2, cmpstr) << std::endl;
  // pass in a lambda
  std::cout << minTD(s1, s2, [](std::string a, std::string b) { 
    return a.size() < b.size();
  }) << std::endl;
}
