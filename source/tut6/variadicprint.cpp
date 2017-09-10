#include <iostream>
#include <vector>

// give the two templates
// need to write the variadic template
// need to explain what is going on.  

template <typename T>
bool printIfWholeNumber(const T&) {
  return false;
}

bool printIfWholeNumber(const int& i) {
  std::cout << i;
  return true;
}

template <typename T>
unsigned int printAndCountWholeNumbers(const T& d) {
  if (printIfWholeNumber(d)) {
    std::cout << " ";
    return 1;
  }
  return 0;
}

// disclaimer: this is bad. We'll talk about perfect forwarding later
template <typename T, typename... U>
unsigned int printAndCountWholeNumbers(T head, U... tail) {
  return printAndCountWholeNumbers(head) + printAndCountWholeNumbers(tail...);
}

template <typename T>
unsigned printAndCountWholeNumbers(const std::vector<T>& vec) {
  auto sum = 0U;
  for (const auto& val : vec) {
    if (static_cast<T>(static_cast<int>(val)) == val)
      sum += printAndCountWholeNumbers(static_cast<int>(val));
  }
  return sum;
}

int main() {
  printIfWholeNumber("hello");
  printIfWholeNumber(1.0);
  printIfWholeNumber(2L);
  printIfWholeNumber(3U);
  printIfWholeNumber(4);
  std::cout << '\n';
  
  // why does 7.0 not get printed?
  auto c = printAndCountWholeNumbers(1,2.5,3,4.5,5.5,6,7.0,-5,"2");
  std::cout << "count = " << c << std::endl;
  
  // why does 32 print this time?
  std::vector<double> d = {1.2,32.0,3.2,5.30,5.4,6,-5};
  auto dc = printAndCountWholeNumbers(d);
  std::cout << "count = " << dc << std::endl;
  
  std::vector<unsigned int> vui = { 65,343,21,3};
  dc = printAndCountWholeNumbers(vui);
  std::cout << "count = " << dc << std::endl;
}
