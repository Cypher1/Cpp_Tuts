#include<iostream>

class Clock {
friend std::ostream& operator<<(std::ostream&, const Clock&);
public:
  Clock(int h=12, int m=0) : hour{h}, min{m} { }
                              // noon by default
  Clock& operator++();       // prefix 
  Clock operator++(int);      // postfix 
private:
  void tick();                // advance clock by 1 min
  int hour, min;
};
