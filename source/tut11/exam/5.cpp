#include <iostream>
#include <string>

class Base {
  public:
    virtual void f(float) {
      std::cout << "Base::f(float)\n";
    }
};

class Derived : public Base {
  public:
    //using Base::f;
    virtual void f(int) {
      std::cout << "Derived::f(int)\n";
    }
    virtual void f(std::string) {
      std::cout << "Derived::f(str)\n";
    }
};
int main() {
  Derived *d = new Derived();
  Base *b = d;
  b->f(3.14F);
  d->f(3.14F);
}
