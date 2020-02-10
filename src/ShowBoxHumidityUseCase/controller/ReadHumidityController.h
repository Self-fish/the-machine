#ifndef ReadHumidityController_h
#define ReadHumidityController_h

#include "Arduino.h"
#include "../../lib/DHT/DHT.h"

class ReadHumidityController {

public:
  ReadHumidityController(DHT* h);
  double readHumidity();

private:
  DHT* humiditySensor;

};


#endif
