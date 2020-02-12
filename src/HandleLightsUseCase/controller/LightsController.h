#ifndef LightsController_h
#define LightsController_h

#include "Arduino.h"

#define LIGHTS_PIN 7

class LightsController {

public:
  LightsController();
  void turnOnLights();
  void turnOffLights();
  int lightsStatus();

private:

};


#endif
