#include "CurrentStatusController.h"

CurrentStatusController::CurrentStatusController() {
  mainScreenActive = false;
}

bool CurrentStatusController::isMainScreenActive() {
  return mainScreenActive;
}

void CurrentStatusController::setIsMainScreenActive(bool isActive) {
  mainScreenActive = isActive;
}
