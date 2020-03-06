#include "AlertMenuScreenController.h"


AlertMenuScreenController::AlertMenuScreenController(LCDController* lController) {
  lcdController = lController;
  menuPosition = 0;
}

void AlertMenuScreenController::showMenu() {
  lcdController->cleanRow(1);
  lcdController->cleanRow(2);
  lcdController->cleanRow(3);
  lcdController->printText(5, 2, "-> Done");
  lcdController->printText(8, 3, "Later");
}

void AlertMenuScreenController::selectFirst() {
  if(menuPosition != 0) {
    lcdController->cleanCharacter(5, 3);
    lcdController->cleanCharacter(6, 3);
    lcdController->printText(5, 2, "-> Done");
    lcdController->printText(8, 3, "Later");
  }
  menuPosition = 0;
}


void AlertMenuScreenController::selectSecond() {
  if(menuPosition != 1) {
    lcdController->cleanCharacter(5, 2);
    lcdController->cleanCharacter(6, 2);
    lcdController->printText(8, 2, "Done");
    lcdController->printText(5, 3, "-> Later");
  }
  menuPosition = 1;
}

int AlertMenuScreenController::getMenuPosition() {
  return menuPosition;
}

void AlertMenuScreenController::closeMenu() {
  freeResources();
}

void AlertMenuScreenController::freeResources() {
  free(lcdController);
}
