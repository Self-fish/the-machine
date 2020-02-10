#include "ReadTemperatureController.h"

ReadTemperatureController::ReadTemperatureController(DHT* t){
  temperatureSensor = t;
}

double ReadTemperatureController::readTemperature() {
  return temperatureSensor->readTemperature();
}
