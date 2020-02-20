#ifndef ReadHumidityController_h
#define ReadHumidityController_h

#include "Arduino.h"
#include "../../lib/DHT/DHT.h"

#define HUMIDITY_PIN 6
#define DHTTYPE DHT22

class ReadHumidityController {

public:
  ReadHumidityController(DHT* h);
  double readHumidity();

private:
  DHT* humiditySensor;

};


#endif
