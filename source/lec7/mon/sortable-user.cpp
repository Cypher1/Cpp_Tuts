// Sortable-user.cpp

//{-bor} (Because of bitset in Urand.h)
// Testing template specialization.
#include <iostream>
#include <array>
#include "Sortable.h"
#include "Urand.h"
 
int main() {
  std::array<std::string, 5> words = { "is", "running", "big", "dog", "a", };
  std::array<std::string, 3> words2 = { "short", "long", "longer", };
  Sortable<int> is;
  Urand<47> rnd;
  for(std::size_t i = 0; i < 15; ++i)
    is.push_back(static_cast<int>(rnd()));
  std::cout << "Random numbers: ";
  for(std::size_t i = 0; i < is.size(); ++i)
    std::cout << is[i] << ' ';
  std::cout << std::endl;
  is.sort();
  std::cout << "Sorted numbers: ";
  for(std::size_t i = 0; i < is.size(); ++i)
    std::cout << is[i] << ' ';
  std::cout << std::endl;
 
  // Uses the template partial specialization:
  std::cout << "template partial specialization using pointers" << std::endl;
  Sortable<std::string*> ss;
  for(std::size_t i = 0; i < words2.size(); ++i)
    ss.push_back(new std::string(words2[i]));
  for(size_t i = 0; i < ss.size(); ++i)
    std::cout << *ss[i] << ' ';
  std::cout << std::endl;
  ss.sort();
  for(std::size_t i = 0; i < ss.size(); ++i) {
    std::cout << *ss[i] << ' ';
    delete ss[i];
  }
  std::cout << std::endl;
 
  // Uses the full std::string specialization:
  std::cout << "template partial specialization using std::string" << std::endl;
  Sortable<std::string> scp;
  for(std::size_t i = 0; i < words2.size(); ++i)
    scp.push_back(words2[i]);
  for(std::size_t i = 0; i < scp.size(); ++i)
    std::cout << scp[i] << ' ';
  std::cout << std::endl;
  scp.sort();
  for(std::size_t i = 0; i < scp.size(); ++i)
    std::cout << scp[i] << ' ';
  std::cout << std::endl;
} ///:~
