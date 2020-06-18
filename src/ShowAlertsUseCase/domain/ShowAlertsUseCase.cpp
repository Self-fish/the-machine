#include "ShowAlertsUseCase.h"

ShowAlertsUseCase::ShowAlertsUseCase(AlertTimeController* tController,
    AlertScreenController* sController, AlertsController* aController,
    JoystickController* jContorller,
    CurrentStatusController* statusController){
  timeController = tController;
  screenController = sController;
  alertsController = aController;
  joystickController = jContorller;
  currentStatusController = statusController;
}

void ShowAlertsUseCase::showAlerts() {
  Serial.println("Menu!");
  int numberOfAlerts = alertsController->getNumberOfAlerts();
  Serial.println(String(numberOfAlerts));
  delay(500);
  if(numberOfAlerts != 0) {
    for(int i=0; i<numberOfAlerts; i++) {
      showSpecificAlert(alertsController->getAllAlerts()[i],
      alertsController->getAllTimeStamps()[i],
      i==numberOfAlerts);
      waitUserInteraction();
    }
  }
  alertsController->cleanAlerts();
  currentStatusController->setIsAlertScreenActive(false);
  freeResources();
}

void ShowAlertsUseCase::showSpecificAlert(char *alertText, time_t alertsDate,
  bool isLastAlert) {
    screenController->printAlert(alertText,
      timeController->getAlertTime(alertsDate), isLastAlert);
}

void ShowAlertsUseCase::waitUserInteraction() {
  bool shouldWait = true;
  while(shouldWait) {
    if(joystickController->wasButtonPressed()) {
      Serial.println("Presionado!");
      shouldWait = false;
      delay(500);
    }
  }
}

void ShowAlertsUseCase::freeResources() {
  screenController->freeResources();
  free(timeController);
  free(screenController);
  free(joystickController);
}
