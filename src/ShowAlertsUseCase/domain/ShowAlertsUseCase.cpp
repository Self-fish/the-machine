#include "ShowAlertsUseCase.h"

ShowAlertsUseCase::ShowAlertsUseCase(AlertTimeController* tController,
    AlertScreenController* sController, AlertsController* aController){
  timeController = tController;
  screenController = sController;
  alertsController = aController;
}

void ShowAlertsUseCase::showAlerts() {
  char* alertText = alertsController->getAllAlerts()[0];
  time_t alertTimestamp = alertsController->getAllTimeStamps()[0];
  screenController->printAlert(alertText, timeController->getAlertTime(alertTimestamp));
  freeResources();
}

void ShowAlertsUseCase::freeResources() {
  free(timeController);
  free(screenController);
}
