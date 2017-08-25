#include <iostream>

// we'll talk about how to do this for generic types when we cover templates
class StringPtr {
public:
  StringPtr(std::string *p): ptr{p} {}

  std::string& operator*() { return *ptr; }
  // define operator-> in terms of operator*
  std::string* operator->() { return &**this; }

private:
  std::string* ptr;
};

int main() {
  StringPtr x{new std::string{"Hello"}};

  // let's try and make the same mistakes we would with C style allocation
  // forget to free
  // double free
  // dereference already freed memory
}
