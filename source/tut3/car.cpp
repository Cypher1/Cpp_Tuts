#include "car.hpp"

unsigned int Car::objectCount = 0;

Car::Car(const Car& c) {
  manufacturer = c.manufacturer;
  numSeats = c.numSeats;
  objectCount++;
}

Car::Car (const Car&& c) {
  manufacturer = std::move(c.manufacturer);
  numSeats = std::move(c.numSeats);
  objectCount++;
}

Car& Car::operator=(const Car& c) {
  manufacturer = c.manufacturer;
  numSeats = c.numSeats;
  return *this;
}

Car& Car::operator=(const Car&& c) {
  manufacturer = std::move(c.manufacturer);
  numSeats = std::move(c.numSeats);
  return *this;
}
