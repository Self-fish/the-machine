#ifndef HandleAlertsAction_h
#define HandleAlertsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/HandleAlertsUseCase.h"

const char SHOW_ALERTS_ACTION[4] = "S_A";

class HandleAlertsAction: public Action {

public:
  HandleAlertsAction(UsbController* uController, HandleAlertsUseCase* uCase);
  void executeAction(char* inputString);

private:
  HandleAlertsUseCase* useCase;
  void freeResources();

};


#endif
