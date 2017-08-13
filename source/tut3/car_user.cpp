#include "car.hpp"

int main() {
  Car one;
  Car two{"Toyota",5};
  
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
  const char* carName = "Average Car";
  Car seven ( std::string{carName}, static_cast<int>(averageNumberOfSeats) );
  seven.getManufacturer();
}
