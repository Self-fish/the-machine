#include "HandleAlertsUseCase.h"

HandleAlertsUseCase::HandleAlertsUseCase(AlertsScreenController* sController) {
  screenContrller = sController;
}

void HandleAlertsUseCase::showAlert(char *alert) {
  screenContrller->configureSpecialCharacters();
  screenContrller->createScreen();
  screenContrller->printAlert(alert);
  freeResources();
}

void HandleAlertsUseCase::freeResources() {
  free(screenContrller);
}
