#ifndef ReadWaterTemperatureController_h
#define ReadWaterTemperatureController_h

#include "Arduino.h"
#include "../../lib/DallasTemperature/DallasTemperature.h"
#include "../../lib/OneWire/OneWire.h"

class ReadWaterTemperatureController {

public:
  ReadWaterTemperatureController(DallasTemperature* t);
  double readTemperature();

private:
  DallasTemperature* temperatureSensor;

};


#endif
