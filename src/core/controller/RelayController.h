#ifndef RelayController_h
#define RelayController_h

#include "Arduino.h"

class RelayController {

public:
  RelayController(int pin);
  void turnOn();
  void turnOff();
  int getValue();

private:
  int relayPin;
};


#endif
