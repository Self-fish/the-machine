#ifndef ShowWelcomeAction_h
#define ShowWelcomeAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowWelcomeUseCase.h"

const char SHOW_WELCOME_SCREEN_ACTION[4] = "S_W";

class ShowWelcomeAction: public Action {
public:
  ShowWelcomeAction(ShowWelcomeUseCase* useCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowWelcomeUseCase* useCase;
  void freeResources();
};


#endif
