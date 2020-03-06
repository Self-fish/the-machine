#include "HandleAlertsAction.h"

HandleAlertsAction::HandleAlertsAction(UsbController* uController,
    HandleAlertsUseCase* uCase) : Action(uController) {
  useCase = uCase;
}


void HandleAlertsAction::executeAction(char *inputString) {
  if(useCase->showAlert("Change water!") == DONE){
    usbController->sendString(OK);
  } else {
    usbController->sendString(LATER_RESPONSE);
  }

  freeResources();
}

void HandleAlertsAction::freeResources() {
  free(usbController);
  free(useCase);
}
