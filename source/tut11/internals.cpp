#include <iostream>

class A1 {
public:
  A1() {
    std::cout << "A1 ";
  }
  ~A1() {
    std::cout << "~A1 ";
  }
};

class A2 {
public:
  A2() {
    std::cout << "A2 ";
    a1 = new A1();
  }
  ~A2() {
    std::cout << "~A2 ";
    delete a1;
  }
private:
  A1 *a1;
};

class A3 {
public:
  A3() {
    std::cout << "A3 ";
    a1 = new A1();
    a2 = new A2();
  }

  ~A3() {
    std::cout << "~A3 ";
    delete a1;
    delete a2;
  }
private:
  A1 *a1;
  A2 *a2;
};

int main() {
  A3 *a3 = new A3();

  std::cout << std::endl;
  delete a3;
  std::cout << std::endl;
}
