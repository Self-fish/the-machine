#include "HandleAlertsUseCase.h"

HandleAlertsUseCase::HandleAlertsUseCase(AlertsScreenController* sController,
    GetTimeController* tController) {
  screenContrller = sController;
  timeController = tController;
}

void HandleAlertsUseCase::showAlert(char *alert) {
  screenContrller->configureSpecialCharacters();
  screenContrller->createScreen(timeController->getCurrentTime(),
    timeController->getCurrentDate());

  while(true) {
    screenContrller->printAlert(alert);
    delay(1000);
    screenContrller->hideAlert();
    delay(400);
  }

  freeResources();
}

void HandleAlertsUseCase::freeResources() {
  free(screenContrller);
  free(timeController);
}
