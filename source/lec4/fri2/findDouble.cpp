#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
  double a[ ] = { 1.1, 2.2, 3.3 };
  list<double> il(a, a + 3);
  
  auto presult = find(il.begin(), il.end(), 2.2);
  if (presult == il.end() )
     cout << "2.2 not found" << endl;
  else
     cout << "2.2 found" << endl;
}
