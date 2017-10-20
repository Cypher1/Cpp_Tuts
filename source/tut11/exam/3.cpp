#include <iostream>
#include <string>
class Y {
  public:
    std::string* operator->() {
           return new std::string("abc");
         }
};
class X
{
  public:
    Y* operator->() {
      return new Y();
    }
};
int main() {
  X x;
  std::cout << x->size() << std::endl;
}
