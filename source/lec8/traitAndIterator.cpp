#include <algorithm>
#include <forward_list>
#include <iostream>

#include "list.hpp"

template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type
last_value(InputIterator  first, InputIterator last) {
  typename std::iterator_traits<InputIterator>::value_type result = *first;
  for (; first != last; ++first)
    result = *first;
  return result;
} 

template <typename BidirectionalIterator>
void myreverse(BidirectionalIterator begin, BidirectionalIterator end) {
  while ((begin != end) && (begin != --end)) {
    std::swap(*begin, *end);
    ++begin;
  }
}

int main() {
  List<int>  l;

  l.push_back(4);
  l.push_back(3);

  std::forward_list<int> fl;
  // std::reverse(fl.begin(), fl.end());
 
  std::cout << last_value(l.begin(), l.end()) << std::endl;
}
