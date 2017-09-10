#include <utility>      
#include <iostream>    

// function with lvalue and rvalue reference overloads:
void overloaded (const int& x) { std::cout << "[lvalue]"; } 
void overloaded (int&& x) { std::cout << "[rvalue]"; } 

template <class T> void foo(T&& x) {
  overloaded (x);                   // always an lvalue
  overloaded (std::forward<T>(x));  // rvalue if argument is rvalue
}

int main () {
  int a;
  std::cout << "calling foo with lvalue: ";
  foo(a);
  std::cout << std::endl;
  std::cout << "calling foo with rvalue: ";
  foo(0);
  std::cout << std::endl;
}
