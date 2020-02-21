#ifndef MachineConfigurationAction_h
#define MachineConfigurationAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../controller/TimeController.h"

const char CONFIGURE_ACTION[4] = "CON";

class MachineConfigurationAction: public Action {
public:
  MachineConfigurationAction(TimeController* c,
    UsbController* uController);
  void executeAction(char* inputString);

private:
  TimeController* controller;
  char* extractArguments(char action[100]);
  void freeResources();
};


#endif
