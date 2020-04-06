#ifndef ShowAlertsAction_h
#define ShowAlertsAction_h

#include "../../core/action/Action.cpp"
#include "../domain/ShowAlertsUseCase.h"

const char SHOW_ALERTS_ACTION[4] = "S_A";

class ShowAlertsAction: public Action {

public:
  ShowAlertsAction(ShowAlertsUseCase* uCase,
    UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowAlertsUseCase* useCase;
  void freeResources();

};


#endif
