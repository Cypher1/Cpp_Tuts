#include<iostream>
#include<algorithm>

#include "list.hpp"

template <typename T> void display(T& c) {
  std::cout << "Iterating over List: ";
  for (auto i = c.begin(); i != c.end(); ++i)
  // or for (auto i = c.begin(); i != c.end(); ++i)
    std::cout << *i << " ";
  std::cout << '\n';

  for (const auto& i : c) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

int main() {
  List<int> l;

  l.push_back(4);
  l.push_back(3);
  l.push_back(2);
  l.push_back(1);

  display(l);

  // use our iterator with a stl algorithm. 
  List<int>::iterator i = std::find(l.begin(), l.end(), 3);
  if (i != l.end())
     std::cout << "3 found" << std::endl;
  else
     std::cout << "3 not found" << std::endl;
}
