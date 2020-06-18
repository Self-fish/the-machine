#include "CurrentStatusController.h"

CurrentStatusController::CurrentStatusController() {
  mainScreenActive = false;
  alertScreenActive = false;
}

bool CurrentStatusController::isMainScreenActive() {
  return mainScreenActive;
}

void CurrentStatusController::setIsMainScreenActive(bool isActive) {
  mainScreenActive = isActive;
}

bool CurrentStatusController::isAlertSreenActive() {
  return alertScreenActive;
}

void CurrentStatusController::setIsAlertScreenActive(bool isActive){
  alertScreenActive = isActive;
}
