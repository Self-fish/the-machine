#include "AlertsController.h"

AlertsController::AlertsController() {
  arrayPos = 0;
  alerts[3] = {};
  alertsTimeStamp[3] = {};
}

void AlertsController::setAlert(char *alert) {
  Serial.println("Set Alert: ");
  Serial.print(alert);
  Serial.println(" ");
  if(!alertAlreadyExist(alert)) {
    addAlert(alert);
  }
}

void AlertsController::cleanAlerts() {
  alerts[3] = {};
  alertsTimeStamp[3] = {};
  arrayPos = 0;
}

bool AlertsController::alertAlreadyExist(char *alert) {
  for(int i=0; i<ALERTS_SIZE; i++) {
    if(strcmp(alerts[i], alert) == 0) {
      return true;
    }
  }
  return false;
}

void AlertsController::addAlert(char *alert) {
  Serial.println("Add Alert");
  if(arrayPos == 3) {
    removeOlderAlert();
  }
  alerts[arrayPos] = alert;
  alertsTimeStamp[arrayPos] = now();
  arrayPos++;
  Serial.println("Next Position: " + String(arrayPos));
}

void AlertsController::removeOlderAlert() {
  Serial.println("Remove alert");
  time_t olderTimestamp = 99999999;
  int positionToDelete = -1;
  for(int i=0; i<ALERTS_SIZE; i++) {
    if(alertsTimeStamp[i] < olderTimestamp) {
      olderTimestamp = alertsTimeStamp[i];
      positionToDelete = i;
    }
  }

  Serial.println("Alert to remove: " + String(positionToDelete));
  for(int i=positionToDelete; i<ALERTS_SIZE-1; i++) {
    alerts[i] = alerts[i+1];
    alertsTimeStamp[i] = alertsTimeStamp[i+1];
  }
  arrayPos = 2;
}

char** AlertsController::getAllAlerts() {
  return alerts;
}

unsigned long int* AlertsController::getAllTimeStamps() {
  return alertsTimeStamp;
}
