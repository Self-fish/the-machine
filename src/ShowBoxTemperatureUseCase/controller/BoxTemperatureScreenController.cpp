#include "BoxTemperatureScreenController.h"

BoxTemperatureScreenController::BoxTemperatureScreenController(LCDController* controller){
  lcdController = controller;
}

void BoxTemperatureScreenController::printBoxTemperature(char* temperature) {
  lcdController->writeCharacter(7, 9, 2);
  lcdController->printText(11, 2, "= " + String(temperature) + "C");
  freeResources();
}

void BoxTemperatureScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(fire, 7);
}

void BoxTemperatureScreenController::freeResources() {
  free(lcdController);
}
