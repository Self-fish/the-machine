#include "BoxTemperatureScreenController.h"

BoxTemperatureScreenController::BoxTemperatureScreenController(LCDController* controller){
  lcdController = controller;
}

void BoxTemperatureScreenController::printBoxTemperature(char* temperature) {
  lcdController->writeCharacter(6, 9, 2);
  lcdController->printText(11, 2, "= " + String(temperature) + "C");
}

void BoxTemperatureScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(fire, 6);
}
