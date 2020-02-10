#ifndef MachineConfigurationUseCase_h
#define MachineConfigurationUseCase_h

#include "../controller/TimeController.h"

class MachineConfigurationUseCase {

public:
  MachineConfigurationUseCase(TimeController* tController);
  void configure(long currentTimeInMilis);

private:
  TimeController* timeController;

};


#endif
