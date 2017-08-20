#pragma once

#include <string>

class Car {
public:
  Car();
  Car(const std::string& manufacturer, unsigned numSeats);
  Car(const Car&);
  Car(Car&&);
  Car& operator=(const Car&) = default;
  Car& operator=(Car&&) = default;
  ~Car() noexcept;

  const std::string& getManufacturer() const;

  static unsigned getObjectCount();

private:
  std::string _manufacturer;
  unsigned int _numSeats;

  static unsigned numCars;
};
