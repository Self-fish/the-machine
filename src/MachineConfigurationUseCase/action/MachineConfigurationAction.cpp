#include "MachineConfigurationAction.h"

MachineConfigurationAction::MachineConfigurationAction(
    MachineConfigurationUseCase* machineConfigUseCase,
    UsbController* uController) : Action(uController){
  useCase = machineConfigUseCase;
}

void MachineConfigurationAction::executeAction(char* inputString) {
  useCase->configure(atol(extractArguments(inputString)));
  usbController->sendString(OK);
}

char* MachineConfigurationAction::extractArguments(char *action) {
  return action + 4;
}
