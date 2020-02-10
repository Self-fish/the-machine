#ifndef ShowWelcomeAction_h
#define ShowWelcomeAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowWelcomeUseCase.h"

class ShowWelcomeAction: public Action {
public:
  ShowWelcomeAction(ShowWelcomeUseCase* useCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowWelcomeUseCase* useCase;
};


#endif
