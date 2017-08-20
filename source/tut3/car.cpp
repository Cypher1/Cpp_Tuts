#include "car.hpp"

unsigned Car::numCars{0U};

Car::Car(const std::string& manufacturer, unsigned numSeats): _manufacturer{manufacturer}, _numSeats{numSeats} {
  ++numCars;
}

Car::Car(): Car{"unknown", 4U} {}

Car::Car(const Car& c): Car{c._manufacturer, c._numSeats} {
}

Car::Car(Car&& c): Car{std::move(c._manufacturer), std::move(c._numSeats)} {}

Car::~Car() {
  --numCars;
}

const std::string& Car::getManufacturer() const {
  return _manufacturer;
}

unsigned Car::getObjectCount() {
  return numCars;
}
