#include "HandleAlertsAction.h"

HandleAlertsAction::HandleAlertsAction(UsbController* uController,
    HandleAlertsUseCase* uCase) : Action(uController) {
  useCase = uCase;
}


void HandleAlertsAction::executeAction(char *inputString) {
  useCase->showAlert("Change water!");
  usbController->sendString(OK);
  freeResources();
}

void HandleAlertsAction::freeResources() {
  free(usbController);
  free(useCase);
}
