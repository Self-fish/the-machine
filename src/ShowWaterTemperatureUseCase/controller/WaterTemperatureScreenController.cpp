#include "WaterTemperatureScreenController.h"

WaterTemperatureScreenController::WaterTemperatureScreenController(LCDController* controller){
  lcdController = controller;
}

void WaterTemperatureScreenController::printWaterTemperature(char* temperature) {
  lcdController->writeCharacter(6, 9, 2);
  lcdController->printText(11, 2, "= " + String(temperature) + "C");
}

void WaterTemperatureScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(water1, 6);
}
