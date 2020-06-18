#ifndef ActionHandler_h
#define ActionHandler_h

#include "../../../lib/VariableTimedAction/src/VariableTimedAction.h"
#include "ActionBuilder.h"
#include "../../../lib/MemoryFree/MemoryFree.h"


class ActionHandler: public VariableTimedAction {

public:
  ActionHandler();
  unsigned long run();
  void executeAction(char* action);

private:
  Action* action;
  ActionBuilder actionBuilder;

};

#endif
