#ifndef ActionHandler_h
#define ActionHandler_h

//#include "../../../lib/VariableTimedAction/src/VariableTimedAction.h"
#include "ActionBuilder.h"
#include "../../../lib/MemoryFree/MemoryFree.h"


class ActionHandler {

public:
  ActionHandler(/*JoystickController* jController*/);
  unsigned long run();
  void executeAction(char action[100]);

private:
  Action* action;
  ActionBuilder actionBuilder;
  AlertsController* alertsController;
};

#endif
