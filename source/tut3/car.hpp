#ifndef CAR_HPP
#define CAR_HPP

// below is the starter code. 

#include <iostream>

/*class Car {
public:

private:
  std::string manufacturer;
  unsigned int numSeats;
};*/

class Car {
public:
  Car(std::string s,unsigned int i): manufacturer{s}, numSeats{i} {objectCount++;};
  Car(): Car{"generic",4} {};
  ~Car() {objectCount--;}
  Car (const Car& c);
  Car (const Car&& c);
  
  Car& operator=(const Car& c);
  Car& operator=(const Car&& c);
  
  std::string getManufacturer() const { return manufacturer; }
  unsigned int getNumSeats() const { return numSeats; } 
  static unsigned int getObjectCount() { return objectCount; }
private:
  std::string manufacturer;
  unsigned int numSeats;
  static unsigned int objectCount;
};

#endif
