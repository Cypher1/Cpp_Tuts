#include <iostream>
#include <memory>

template <typename T>
std::unique_ptr<T> make_unique(T t) {
  // why are we allowed to use new inside make_unique, but nowhere else?
  // If make_unique calls new, why is it any better practice to call make_unique than to call new yourself?
  return std::unique_ptr<T>(new T(t));
}

template <typename T>
std::unique_ptr<T> make_unique(std::unique_ptr<T>& up) {
  return make_unique(*up);;
} 

// TODO: extension exercise: make a variadic version of make_unique that works same way as in standard library. Why can't we deduce template parameter?

template <typename T>
T getBase(T t) {
  return t;
}

const char* getBase(const char* t) {
  return t;
}

template <typename T>
auto getBase(T *t) -> decltype(*t) {
  return *t;
}

template <typename T>
auto getBase(std::unique_ptr<T>& t) -> decltype(*t) {
  return *t;
}

int main() {
  auto dptr = make_unique(3.14);
  std::cout << *dptr << std::endl;
  
  auto dptr2 = make_unique(dptr);
  std::cout << *dptr2 << std::endl;
  std::cout << *dptr << std::endl;
  
  int i = 9;
  int* iptr = &i;
  std::cout << getBase(i) << std::endl;
  std::cout << getBase(iptr) << std::endl;
  std::cout << getBase(dptr) << std::endl;

  const char* str = "hello";
  std::cout << getBase(str) << std::endl;
}
