#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// TODO: write type transformation here

template <typename T, typename U>
auto findmin(U begin, U end) {
  // TODO: I don't want to have to specify T. How can we fix this? decltype? may need a type transformation
  // using T = ???;
  auto min = std::numeric_limits<T>::max();
  for (; begin != end; ++begin)
    min = std::min(*begin, min); // this is why you don't go using namespace std
  return min;
}

int main() {
  std::cout << std::numeric_limits<int>::min() << '\n';
  std::cout << std::numeric_limits<int>::min() << '\n';

  std::vector<int> vi{5, 1, 2, 3, 7, 4};
  std::vector<int> vempty;
  std::vector<std::string> vs{"hello", "world"};
  
  // also see std::min_element
  std::cout << "min of vi is " << findmin<int>(vi.cbegin(), vi.cend()) << '\n';
  std::cout << "min of vempty is " << findmin<int>(vempty.cbegin(), vempty.cend()) << '\n';

  // this clearly doesn't work the way we want it to. How can we use type traits to ensure this template only works for numbers?
  std::cout << "min of vs is " << findmin<std::string>(vs.cbegin(), vs.cend()) << '\n';
}
