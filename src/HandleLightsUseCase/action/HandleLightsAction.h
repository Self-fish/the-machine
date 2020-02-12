#ifndef HandleLightsAction_h
#define HandleLightsAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/HandleLightsUseCase.h"

const char LIGHT_ON_ACTION[4] = "L_N";
const char LIGHT_OFF_ACTION[4] = "L_F";
const char LIGHT_GET_ACTION[4] = "L_G";

class HandleLightsAction: public Action {
public:
  HandleLightsAction(HandleLightsUseCase* useCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  HandleLightsUseCase* useCase;
};


#endif
