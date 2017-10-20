#include <iostream>

using namespace std;

class A1 {
  public:
    ~A1() { cout << "~A1 "; }
};

class A2 {
  public:
    ~A2() { cout << "~A2 "; }

  private:
    A1 a1;
};

class A3 {
  public:
    ~A3() { cout << "~A3 "; }

  private:
    A1 a1;
    A2 a2;
};

int main() {
  A3 a3;
}
