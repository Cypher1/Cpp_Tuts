#include "Clock.h"

Clock& Clock::operator++() {   // prefix 
  tick();           // increment
  return *this;     // return itself for assignment
}

Clock Clock::operator++(int) { // postfix 
  Clock c = *this;  // Save/copy the object.
  tick();           // Increment the object.
  return c;         // Return the original object
}

void Clock::tick() {  // Advance the object's min by 1
  min = (min + 1) % 60;
  if (min == 0) 
    hour = (hour + 1) % 24;
}

std::ostream& operator<<(std::ostream& os, const Clock& c) {
  if (c.hour < 10)   
     os << '0';
  os << c.hour << ":";
  if (c.min < 10)       
    os << '0';
  os << c.min;
  return os;
}
