#include "WaterTemperatureScreenController.h"

WaterTemperatureScreenController::WaterTemperatureScreenController(LCDController* controller){
  lcdController = controller;
}

void WaterTemperatureScreenController::printWaterTemperature(char* temperature) {
  lcdController->writeCharacter(7, 9, 2);
  lcdController->printText(11, 2, "= " + String(temperature) + "C");
  freeResources();
}

void WaterTemperatureScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(water1, 7);
}

void WaterTemperatureScreenController::freeResources() {
  free(lcdController);
}
