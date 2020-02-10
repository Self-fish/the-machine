#include "BoxHumidityScreenController.h"

BoxHumidityScreenController::BoxHumidityScreenController(LCDController* controller){
  lcdController = controller;
}

void BoxHumidityScreenController::printBoxHumidity(char* humidity) {
  lcdController->writeCharacter(6, 9, 2);
  lcdController->printText(11, 2, "= " + String(humidity) + "%");
}

void BoxHumidityScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(waterDrop, 6);
}
