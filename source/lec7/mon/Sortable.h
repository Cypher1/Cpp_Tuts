// Sortable.h

#ifndef SORTABLE_H
#define SORTABLE_H
#include <string>
#include <vector>
 
template<typename T>
class Sortable : public std::vector<T> {
public:
  void sort();
};
 
template<typename T>
void Sortable<T>::sort() { // A simple sort
  for(std::size_t i = this->size(); i > 0; --i)
    for(std::size_t j = 1; j < i; ++j)
      if(this->at(j-1) > this->at(j)) {
        T t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}

// Partial specialization for pointers:
template<typename T>
class Sortable<T*> : public std::vector<T*> {
public:
  void sort();
};

template<typename T>
void Sortable<T*>::sort() {
  for(std::size_t i = this->size(); i > 0; --i)
    for(std::size_t j = 1; j < i; ++j)
      if(*this->at(j-1) > *this->at(j)) {
        T* t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}
 
// Full specialization for std::string
// Sorts by length rather than character by character
template<> inline void Sortable<std::string>::sort() {
  for(std::size_t i = this->size(); i > 0; --i)
    for(std::size_t j = 1; j < i; ++j)
      if(this->at(j-1).size() > this->at(j).size()) {
        std::string t = this->at(j-1);
        this->at(j-1) = this->at(j);
        this->at(j) = t;
      }
}
#endif // SORTABLE_H ///:~
