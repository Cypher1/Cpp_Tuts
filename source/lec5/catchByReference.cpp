#include <iostream>

class X { 
public:
  X() { std::cout << "X constructed" << std::endl; }
  X(const X &x) { std::cout << "X copy-constructed" << std::endl; }
  ~X() { std::cout << "X destructed" << std::endl; }
};

void g() {
  throw X();
}

void f() {
  try {
    g();
  } catch (X& x) {
    std::cout << "caught in f; rethrow" << std::endl;
    throw;
  }
}

int main() {
  try {
    f();
  } catch (X& x) {
    std::cout << "caught in main" << std::endl;
  }
} // How many objects created?  A: 1  B: 2  C: 3  D: 4 
