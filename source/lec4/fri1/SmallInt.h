#include<iostream>

class SmallInt {
  friend std::ostream& operator<<(std::ostream &os, const SmallInt &s);
  friend bool operator<(const SmallInt&,const SmallInt&);
public:
  SmallInt(int v) : value_{v} { }
private:
  int value_;
};

std::ostream& operator<<(std::ostream &os, const SmallInt &s);
bool operator<(const SmallInt&,const SmallInt&);
