#ifndef MachineConfigurationAction_h
#define MachineConfigurationAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/MachineConfigurationUseCase.h"

class MachineConfigurationAction: public Action {
public:
  MachineConfigurationAction(MachineConfigurationUseCase* machineConfigUseCase,
    UsbController* uController);
  void executeAction(char* inputString);

private:
  MachineConfigurationUseCase* useCase;
  char* extractArguments(char action[100]);
};


#endif
