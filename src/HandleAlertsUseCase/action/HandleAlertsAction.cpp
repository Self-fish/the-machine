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
  /*if(useCase->showAlert(alertText) == DONE){
    usbController->sendString(OK);
  } else {
    usbController->sendString(LATER_RESPONSE);
  }*/
  freeResources();
}

char* HandleAlertsAction::extractArguments(char *action) {
  return action + 4;
}

void HandleAlertsAction::freeResources() {
  free(usbController);
  free(storeAlertUseCase);
}
