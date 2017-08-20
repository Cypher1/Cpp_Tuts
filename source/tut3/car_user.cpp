#include "car.hpp"

#include <iostream>

int main() {
  Car one;
  const Car two{"Toyota",5};
  two.getManufacturer();
  
  std::cout << Car::getObjectCount() << std::endl;
  
  Car* three = new Car{};
  std::cout << Car::getObjectCount() << std::endl;
  delete three;
  std::cout << Car::getObjectCount() << std::endl;
  
  Car four{two};
  std::cout << Car::getObjectCount() << std::endl;
  
  Car five = std::move(one);
  std::cout << Car::getObjectCount() << std::endl;
  
  Car six{std::move(two)};
  std::cout << Car::getObjectCount() << std::endl;
  
  four = six;
  std::cout << Car::getObjectCount() << std::endl;
  
  five = std::move(six);
  std::cout << Car::getObjectCount() << std::endl;
 
  
  double averageNumberOfSeats = 3.2;
  Car seven{
      "Average Car", 
      static_cast<unsigned>(averageNumberOfSeats)
  };
  seven.getManufacturer();
  
}
