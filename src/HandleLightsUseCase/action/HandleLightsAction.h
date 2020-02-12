#ifndef HandleLightsAction_h
#define HandleLightsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/HandleLightsUseCase.h"

class HandleLightsAction: public Action {
public:
  HandleLightsAction(HandleLightsUseCase* useCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  HandleLightsUseCase* useCase;
};


#endif
