#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

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
  (void)begin;
  (void)end;
}

int main() {
  List<int>  l;

  l.push_back(4);
  l.push_back(3);

  std::forward_list<int> fl;
  std::vector<int> vec;
  std::list<int> ls;
  myreverse(fl.begin(), fl.end());
  myreverse(vec.begin(), vec.end());
  myreverse(ls.begin(), ls.end());
  // std::reverse(fl.begin(), fl.end());
  std::reverse(vec.begin(), vec.end());
  std::reverse(ls.begin(), ls.end());
 
  std::cout << last_value(l.begin(), l.end()) << std::endl;
}
