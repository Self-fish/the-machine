#include "MachineConfigurationInyector.h"

MachineConfigurationAction* MachineConfigurationInyector::actionInstance = 0;

MachineConfigurationInyector::MachineConfigurationInyector() {}

MachineConfigurationAction* MachineConfigurationInyector::getMachineConfigurationAction() {
  if(actionInstance == 0) {
    actionInstance = new MachineConfigurationAction(getTimeController(),
      getUsbController());
  }
  return actionInstance;
}

TimeController* MachineConfigurationInyector::getTimeController() {
  return new TimeController();
}
