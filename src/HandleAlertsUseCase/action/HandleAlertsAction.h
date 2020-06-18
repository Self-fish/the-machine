#ifndef HandleAlertsAction_h
#define HandleAlertsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/StoreAlertUseCase.h"

const char RECEIVE_ALERTS_ACTION[4] = "R_A";

class HandleAlertsAction: public Action {

public:
  HandleAlertsAction(UsbController* uController,
    StoreAlertUseCase* storeUseCase);
  void executeAction(char* inputString);

private:
  StoreAlertUseCase* storeAlertUseCase;
  char* extractArguments(char *action);
  void freeResources();

};


#endif
