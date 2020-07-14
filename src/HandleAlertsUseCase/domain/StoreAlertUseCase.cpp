#include "StoreAlertUseCase.h"

StoreAlertUseCase::StoreAlertUseCase(/*AlertsController* aController,*/
    CurrentStatusController* statusController) {
  //alertsController = aController;
  currentStatusController = statusController;
}

void StoreAlertUseCase::storeAlert(char *alertText) {
  //alertsController->setAlert(alertText);
  currentStatusController->setIsAlertScreenActive(true);
}
