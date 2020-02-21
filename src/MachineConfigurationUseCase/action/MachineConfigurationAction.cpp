#include "MachineConfigurationAction.h"

MachineConfigurationAction::MachineConfigurationAction(
    TimeController* c,
    UsbController* uController) : Action(uController){
  controller = c;
}

void MachineConfigurationAction::executeAction(char* inputString) {
  controller->configureTime(atol(extractArguments(inputString)));
  usbController->sendString(OK);
  freeResources();
}

char* MachineConfigurationAction::extractArguments(char *action) {
  return action + 4;
}

void MachineConfigurationAction::freeResources() {
  free(controller);
  free(usbController);
}
