#include "ShowAlertsAction.h"

ShowAlertsAction::ShowAlertsAction(ShowAlertsUseCase* uCase,
  UsbController* uController) : Action(uController) {
    useCase = uCase;
}

void ShowAlertsAction::executeAction(char *inputString) {
  useCase->showAlerts();
  usbController->sendString(OK);
  freeResources();
}

void ShowAlertsAction::freeResources() {
  free(useCase);
  free(usbController);
}
