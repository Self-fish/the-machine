#include "MainScreenController.h"

MainScreenController::MainScreenController(LCDController* controller,
  CurrentStatusController* sController){
  lcdController = controller;
  statusController = sController;
}

void MainScreenController::createScreen() {
  if(!statusController->isMainScreenActive()) {
    lcdController->cleanScreen();
    paintAnchor(3, 1);
    statusController->setIsMainScreenActive(true);
  }
}

void MainScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(anchor0, 0);
  lcdController->createSpecialCharacters(anchor1, 1);
  lcdController->createSpecialCharacters(anchor2, 2);
  lcdController->createSpecialCharacters(anchor3, 3);
  lcdController->createSpecialCharacters(anchor4, 4);
  lcdController->createSpecialCharacters(anchor5, 5);
}

void MainScreenController::paintAnchor(int column, int row) {
  lcdController->writeCharacter(0, column, row);
  lcdController->writeCharacter(1, column-1, row+1);
  lcdController->writeCharacter(1, column+1, row+1);
  lcdController->writeCharacter(2, column, row+1);
  lcdController->writeCharacter(3, column, row+2);
  lcdController->writeCharacter(4, column-1, row+2);
  lcdController->writeCharacter(5, column+1, row+2);
}

void MainScreenController::printDate(String hour, String date) {
  lcdController->printText(1, 0, hour);
  lcdController->printText(8, 0, date);
  freeResources();
}

void MainScreenController::freeResources() {
  free(lcdController);
}
