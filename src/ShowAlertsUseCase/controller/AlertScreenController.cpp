#include "AlertScreenController.h"

AlertScreenController::AlertScreenController(LCDController* lController,
    CurrentStatusController* sController) {
  lcdController = lController;
  statusController = sController;
}

void AlertScreenController::printAlert(char *alertText, String alertDate,
    bool isLastAlert) {
      Serial.println(alertText);
  lcdController->cleanScreen();
  lcdController->printText(1, 0, alertDate);
  lcdController->printText(calculateFirstCharacterScreenPisition(alertText),
    2, alertText);
  statusController->setIsMainScreenActive(false);
}

void AlertScreenController::freeResources() {
  free(lcdController);
}

int AlertScreenController::calculateFirstCharacterScreenPisition(char *alertText) {
  int textLength = strlen(alertText);
  return 10 - textLength / 2;
}
