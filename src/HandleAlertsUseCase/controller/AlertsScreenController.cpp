#include "AlertsScreenController.h"

AlertsScreenController::AlertsScreenController(LCDController* lController,
  CurrentStatusController* statusC) {
    lcdController = lController;
    currentStatusController = statusC;
}

void AlertsScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(warning0, 0);
  lcdController->createSpecialCharacters(warning1, 1);
  lcdController->createSpecialCharacters(warning2, 2);
  lcdController->createSpecialCharacters(warning3, 3);
  lcdController->createSpecialCharacters(warning4, 4);
  lcdController->createSpecialCharacters(warning5, 5);
  lcdController->createSpecialCharacters(warning6, 6);
  lcdController->createSpecialCharacters(warning7, 7);
}

void AlertsScreenController::createScreen(String hour, String date) {
  currentStatusController->setIsMainScreenActive(false);
  lcdController->cleanScreen();
  lcdController->printText(1, 0, hour);
  lcdController->printText(8, 0, date);
}

void AlertsScreenController::paintSignal(int column, int row) {
  lcdController->writeCharacter(0, column, row);
  lcdController->writeCharacter(1, column-1, row+1);
  lcdController->writeCharacter(2, column, row+1);
  lcdController->writeCharacter(3, column+1, row+1);
  lcdController->writeCharacter(4, column-2, row+2);
  lcdController->writeCharacter(5, column-1, row+2);
  lcdController->writeCharacter(5, column+1, row+2);
  lcdController->writeCharacter(6, column, row+2);
  lcdController->writeCharacter(7, column+2, row+2);
}

void AlertsScreenController::hideAlert() {
  lcdController->cleanRow(1);
  lcdController->cleanRow(2);
  lcdController->cleanRow(3);
}

void AlertsScreenController::finishAlert() {
  freeResources();
}

void AlertsScreenController::printAlert(char* alert) {
  paintSignal(3, 1);
  lcdController->printText(6, 2, alert);
}

void AlertsScreenController::freeResources() {
  free(lcdController);
}
