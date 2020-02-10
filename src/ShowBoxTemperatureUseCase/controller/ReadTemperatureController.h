#ifndef ReadTemperatureController_h
#define ReadTemperatureController_h

#include "Arduino.h"
#include "../../lib/DHT/DHT.h"

class ReadTemperatureController {

public:
  ReadTemperatureController(DHT* t);
  double readTemperature();

private:
  DHT* temperatureSensor;

};


#endif
