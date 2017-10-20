#include <list>
#include <iostream>

class X {
  public:
    X() {
      std::cout << "ctor ";
    }

    ~X() {
      std::cout << "dtor ";
    }
};

int main() {
  std::list<X**> l;

  X *x1 = new X();

  X** x2 = &x1;

  l.push_back(x2);
}
