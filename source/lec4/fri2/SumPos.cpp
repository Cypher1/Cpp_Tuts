#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SumPos {  // sum positive int's
public:
  SumPos(int init = 0) : sum(init) { }
  int operator() (int i) {
    if (i > 0) sum += i;
    return sum;
  }
  int getSum() { return sum; }
private:
  int sum;      
};

int main() {
  vector<int> ivec;
  ivec.push_back(1); ivec.push_back(-1);
  ivec.push_back(2); ivec.push_back(-2);
  ivec.push_back(3); ivec.push_back(-3);

  cout << for_each(ivec.begin(), ivec.end(), SumPos(10)).getSum() << endl;
}
