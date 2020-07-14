#include "ShowAlertsUseCase.h"

ShowAlertsUseCase::ShowAlertsUseCase(AlertTimeController* tController,
    AlertScreenController* sController, /*AlertsController* aController,*/
    /*JoystickController* jContorller,*/
    CurrentStatusController* statusController){
  timeController = tController;
  screenController = sController;
  //alertsController = aController;
  //joystickController = jContorller;
  currentStatusController = statusController;
}

/*void ShowAlertsUseCase::showAlerts() {
  int numberOfAlerts = alertsController->getNumberOfAlerts();
  delay(500);
  if(numberOfAlerts != 0) {
    for(int i=0; i<numberOfAlerts; i++) {
      showSpecificAlert(alertsController->getAllAlerts()[i],
        alertsController->getAllTimeStamps()[i],
        i==numberOfAlerts);
      int nextAlert = waitUserSwipe();
      if(nextAlert == -1) {
        if(i == 0) {
          i = -1;
        } else {
          i = i-2;
        }
      }
    }
    screenController->printCloseMenu();
    waitUserClose();
  }
  alertsController->cleanAlerts();
  currentStatusController->setIsAlertScreenActive(false);
  freeResources();
}*/

void ShowAlertsUseCase::showSpecificAlert(char *alertText, time_t alertsDate,
  bool isLastAlert) {
    screenController->printAlert(alertText,
      timeController->getAlertTime(alertsDate), isLastAlert);
}

/*void ShowAlertsUseCase::waitUserClose() {
  bool shouldWait = true;
  while(shouldWait) {
    if(joystickController->wasButtonPressed()) {
      shouldWait = false;
      delay(500);
    }
  }
}*/

/*int ShowAlertsUseCase::waitUserSwipe() {
  bool shouldWait = true;
  while(shouldWait) {
    if(joystickController->wasSwipeRight()) {
      shouldWait = false;
      delay(500);
      return 1;
    } else if (joystickController->wasSwipedLeft()){
      shouldWait = false;
      delay(500);
      return -1;
    }
  }
}*/

void ShowAlertsUseCase::freeResources() {
  screenController->freeResources();
  free(timeController);
  free(screenController);
  //free(joystickController);
}
