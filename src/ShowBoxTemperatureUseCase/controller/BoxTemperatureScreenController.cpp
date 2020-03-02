#include "BoxTemperatureScreenController.h"

BoxTemperatureScreenController::BoxTemperatureScreenController(LCDController* controller){
  lcdController = controller;
}

void BoxTemperatureScreenController::printBoxTemperature(char* temperature) {
  lcdController->writeCharacter(6, 9, 2);
  lcdController->printText(11, 2, "         ");
  lcdController->printText(11, 2, "= " + String(temperature) + "C");
  freeResources();
}

void BoxTemperatureScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(fire, 6);
}

void BoxTemperatureScreenController::freeResources() {
  free(lcdController);
}
