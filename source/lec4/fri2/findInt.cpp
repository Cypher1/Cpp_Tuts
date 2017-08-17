#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int a[ ] = { 1, 2, 3};
  vector<int> vec(a, a + 3);
  
  auto presult = find(vec.begin(), vec.end(), 2);
  if (presult == vec.end() )
     cout << "2 not found" << endl;
  else
     cout << "2 found" << endl;
}
