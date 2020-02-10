#include "ReadWaterTemperatureController.h"

ReadWaterTemperatureController::ReadWaterTemperatureController(
    DallasTemperature* t){
  temperatureSensor = t;
}

double ReadWaterTemperatureController::readTemperature() {
  temperatureSensor->requestTemperatures();
  return (temperatureSensor->getTempCByIndex(0) +
    temperatureSensor->getTempCByIndex(1)) / 2;
}
