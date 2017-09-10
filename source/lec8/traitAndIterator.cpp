#include <iostream>
#include <algorithm>

#include "list.hpp"

template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type
last_value(InputIterator  first, InputIterator last) {
  typename std::iterator_traits<InputIterator>::value_type result = *first;
  for (; first != last; ++first)
    result = *first;
  return result;
} 

int main() {
  List<int>  l;

  l.push_back(4);
  l.push_back(3);
 
  std::cout << last_value(l.begin(), l.end()) << std::endl;
}
