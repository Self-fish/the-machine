#ifndef HandleLightsAction_h
#define HandleLightsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../controller/LightsController.h"

const char LIGHT_ON_ACTION[4] = "L_N";
const char LIGHT_OFF_ACTION[4] = "L_F";
const char LIGHT_GET_ACTION[4] = "L_G";

class HandleLightsAction: public Action {
public:
  HandleLightsAction(LightsController* c, UsbController* uController);
  void executeAction(char* inputString);

private:
  LightsController* controller;
};


#endif
