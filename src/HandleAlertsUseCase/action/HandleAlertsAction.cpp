#include "HandleAlertsAction.h"

HandleAlertsAction::HandleAlertsAction(UsbController* uController,
    StoreAlertUseCase* storeUseCase) :
    Action(uController) {
  storeAlertUseCase = storeUseCase;
}

void HandleAlertsAction::executeAction(char *inputString) {
  char* alertText = extractArguments(inputString);
  storeAlertUseCase->storeAlert(alertText);
  usbController->sendString(OK);
  freeResources();
}

char* HandleAlertsAction::extractArguments(char *action) {
  return action + 4;
}

void HandleAlertsAction::freeResources() {
  free(usbController);
  free(storeAlertUseCase);
}
