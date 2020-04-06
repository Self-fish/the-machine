#include "AlertScreenController.h"

AlertScreenController::AlertScreenController(LCDController* lController,
    CurrentStatusController* sController) {
  lcdController = lController;
  statusController = sController;
}

void AlertScreenController::printAlert(char *alertText, String alertDate) {
  lcdController->cleanScreen();
  lcdController->printText(1, 0, alertDate);
  lcdController->printText(1, 1, alertText);
  statusController->setIsMainScreenActive(false);
  freeResources();
}

void AlertScreenController::freeResources() {
  free(lcdController);
}
