#include "MachineConfigurationUseCase.h"

MachineConfigurationUseCase::MachineConfigurationUseCase(
    TimeController* tController){
  timeController = tController;
}

void MachineConfigurationUseCase::configure(long currentTimeInMilis) {
  timeController->configureTime(currentTimeInMilis);
}
