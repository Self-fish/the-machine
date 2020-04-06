#include "StoreAlertUseCase.h"

StoreAlertUseCase::StoreAlertUseCase(AlertsController* aController) {
  alertsController = aController;
}

void StoreAlertUseCase::storeAlert(char *alertText) {
  alertsController->setAlert(alertText);
}
