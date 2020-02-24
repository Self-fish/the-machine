#ifndef HandleLightsAction_h
#define HandleLightsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../../core/controller/RelayController.h"

#define LIGHTS_PIN 7

const char LIGHT_ON_ACTION[4] = "L_N";
const char LIGHT_OFF_ACTION[4] = "L_F";
const char LIGHT_GET_ACTION[4] = "L_G";

class HandleLightsAction: public Action {
public:
  HandleLightsAction(RelayController* c, UsbController* uController);
  void executeAction(char* inputString);

private:
  RelayController* controller;
  void freeResources();
};


#endif
