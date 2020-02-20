#ifndef ReadWaterTemperatureController_h
#define ReadWaterTemperatureController_h

#include "Arduino.h"
#include "../../lib/DallasTemperature/DallasTemperature.h"
#include "../../lib/OneWire/OneWire.h"

#define WATER_TEMPERATURE_PIN 10

class ReadWaterTemperatureController {

public:
  ReadWaterTemperatureController(DallasTemperature* t);
  double readTemperature();

private:
  DallasTemperature* temperatureSensor;

};


#endif
