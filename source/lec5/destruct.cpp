#include <iostream>

struct X { 
  ~X() { std::cout << "~X() "; }
};

struct Y { 
  ~Y() { std::cout << "~Y() "; }
};

class A { 
  X x;
public:
  ~A() { std::cout << "~A() "; }
};

class B : public A { 
  Y y;
public:
  ~B() { std::cout << "~B() "; }
};

int main() { 
	B b; 
}
