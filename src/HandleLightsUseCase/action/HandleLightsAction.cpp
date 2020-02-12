#include "HandleLightsAction.h"

HandleLightsAction::HandleLightsAction(HandleLightsUseCase* lUseCase,
UsbController* uController) : Action(uController){
  useCase = lUseCase;
}

void HandleLightsAction::executeAction(char* inputString) {
    //useCase->showScreen();
}
