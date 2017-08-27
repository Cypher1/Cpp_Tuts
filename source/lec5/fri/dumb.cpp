#include <iostream>
#include <string>
#include <vector>

int main() {
  auto pi = new int{1};
  auto pj = new int[10];

  std::cout << *pi << '\n';

  // delete[] pi; undefined
  delete pi;
  // delete pj undefined
  delete[] pj;

  // why does this output 0 instead of 1? UB
  std::cout << *pi << '\n'; // undefined behaviour


  auto pi1 = new int;
  auto pi2 = new int{};

  auto ps1 = new std::string;
  auto ps2 = new std::string{"abc"};
  std::cout << *ps2 << '\n';

  auto pf = new auto{3.14};
  std::cout << *pf << '\n';
  auto pci = new const int{100};

  auto pv1 = new std::vector<int>{};
  auto pv2 = new (std::nothrow) std::vector<int>{}; // if this fails, will return nullptr instead of throwing
  delete pi1; 
  delete pi2;
  delete ps1;
  delete ps2;
  delete pf;
  delete pci;
  delete pv1;
  delete pv2;

  auto p1 = new int[5];
  auto p2 = new int[5]{};
  
  auto s1 = new std::string[5];
  auto s2 = new std::string[5]{};
  
  /*
  // not contsructors
  auto p3 = new int[5](1);
  auto s3 = new int[5]("abc");
  */

  // initialiser lists
  auto p4 = new int[5]{0, 2, 3, 4, 5};
  auto s4 = new std::string[5]{"abc"};

  delete[] p1;
  delete[] p2;
  delete[] p4;
  delete[] s1;
  delete[] s2;
  delete[] s4;
}
