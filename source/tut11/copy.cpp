#include <list>
#include <iostream>

class X {
public:
  X() {
    std::cout << "ctor ";
  }
  X(const X&) {
    std::cout << "copy-ctor ";
  }
  ~X() {
    std::cout << "dtor ";
  }
};

int main() {
  std::list<X*> l;
  X *x = new X();
  X y;
  l.push_back(x);
  l.push_back(&y);

  std::list<X> l2;
  l2.push_back(y);
}
