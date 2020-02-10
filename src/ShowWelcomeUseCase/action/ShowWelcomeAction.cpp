#include "ShowWelcomeAction.h"

ShowWelcomeAction::ShowWelcomeAction(ShowWelcomeUseCase* welcomeUseCase,
UsbController* uController) : Action(uController){
  useCase = welcomeUseCase;
}

void ShowWelcomeAction::executeAction(char* inputString) {
    useCase->showScreen();
}
