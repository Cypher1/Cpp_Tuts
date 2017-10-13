#include <iostream>

class B { // Base
public:
  int i;

  B(const int& i): i{i} {
    std::cout << "CONSTRUCT B\n";
  }

  virtual void f() {
    std::cout << "B ";
  }

  virtual ~B() {
    std::cout << "DECONSTRUCTING B\n";
  }
};

class D : public B { // Derived
public:

  D(const int&i): B(i) {
    std::cout << "CONSTRUCT D\n";
  }

  virtual void f() {
    B::f();
    std::cout << "D ";
  }
  virtual ~D() {
    std::cout << "DECONSTRUCTING D\n";
  }
};

int main() {
  D d{1};
  std::cout << "d = ";
  d.f();
  std::cout << std::endl;


  B b = d;
  std::cout << "b = ";
  b.f();
  std::cout << std::endl;


  B &pb = b;
  std::cout << "pb = ";
  pb.f();
  std::cout << std::endl;

  B &pd = d;
  std::cout << "pd = ";
  pd.f();
  std::cout << std::endl;
}
