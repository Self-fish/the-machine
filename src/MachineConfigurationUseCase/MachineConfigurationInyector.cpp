#include "MachineConfigurationInyector.h"

MachineConfigurationAction* MachineConfigurationInyector::actionInstance = 0;

MachineConfigurationInyector::MachineConfigurationInyector() {}

MachineConfigurationAction* MachineConfigurationInyector::getMachineConfigurationAction() {
  if(actionInstance == 0) {
    actionInstance = new MachineConfigurationAction(getMachineConfigurationUseCase(),
      getUsbController());
  }
  return actionInstance;
}

MachineConfigurationUseCase* MachineConfigurationInyector::getMachineConfigurationUseCase() {
  return new MachineConfigurationUseCase(getTimeController());
}

TimeController* MachineConfigurationInyector::getTimeController() {
  return new TimeController();
}
