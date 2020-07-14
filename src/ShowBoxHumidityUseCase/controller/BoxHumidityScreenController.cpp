#include "BoxHumidityScreenController.h"

BoxHumidityScreenController::BoxHumidityScreenController(LCDController* controller){
  lcdController = controller;
}

void BoxHumidityScreenController::printBoxHumidity(char* humidity) {
  lcdController->writeCharacter(7, 9, 2);
  lcdController->printText(11, 2, "= " + String(humidity) + "%");
  freeResources();
}

void BoxHumidityScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(waterDrop, 7);
}

void BoxHumidityScreenController::freeResources() {
  free(lcdController);
}
