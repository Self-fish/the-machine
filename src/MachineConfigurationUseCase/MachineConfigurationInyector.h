#ifndef MachineConfigurationInyector_h
#define MachineConfigurationInyector_h

#include "action/MachineConfigurationAction.h"
#include "../core/CoreInyector.h"

class MachineConfigurationInyector: public CoreInyector {
public:
  MachineConfigurationInyector();
  MachineConfigurationAction* getMachineConfigurationAction();

private:
  static MachineConfigurationAction* actionInstance;
  MachineConfigurationUseCase* getMachineConfigurationUseCase();
  TimeController* getTimeController();
};


#endif
