#include "WelcomeScreenController.h"

WelcomeScreenController::WelcomeScreenController(LCDController* controller,
    CurrentStatusController* statusController){
  lcdController = controller;
  currentStatusController = statusController;
}

void WelcomeScreenController::printWelcomeMessage() {
  currentStatusController->setIsMainScreenActive(false);
  lcdController->printText(3, 1, "Welcome Batman!");
  lcdController->printText(3, 2, "Please wait...");
}

void WelcomeScreenController::printLoading() {
  lcdController->cleanScreen();
  paintFishBank(3);
  createLoadingAnimation();
}

void WelcomeScreenController::configureSpecialCharacters() {
  lcdController->createSpecialCharacters(loadingBar0, 0);
  lcdController->createSpecialCharacters(loadingBar1, 1);
  lcdController->createSpecialCharacters(loadingBar2, 2);
  lcdController->createSpecialCharacters(loadingBar3, 3);
  lcdController->createSpecialCharacters(loadingBar4, 4);
  lcdController->createSpecialCharacters(fish1, 5);
  lcdController->createSpecialCharacters(fish2, 6);
}

void WelcomeScreenController::paintFishBank(int startingColumn) {
  paintFish(startingColumn, 0);
  paintFish(startingColumn+5, 0);
  paintFish(startingColumn+11, 0);
  paintFish(startingColumn+15, 0);
  paintFish(startingColumn-2, 1);
  paintFish(startingColumn+3, 1);
  paintFish(startingColumn+9, 1);
  paintFish(startingColumn+13, 1);
}

void WelcomeScreenController::paintFish(int column, int row) {
  if(column >= 0) {
    lcdController->writeCharacter(5, column, row);
    lcdController->writeCharacter(6, column+1, row);
  } else if(column == -1) {
    lcdController->writeCharacter(5, column+20, row);
    lcdController->writeCharacter(6, column+1, row);
  } else {
    lcdController->writeCharacter(5, column+20, row);
    lcdController->writeCharacter(6, column+20+1, row);
  }
}

void WelcomeScreenController::createLoadingAnimation() {
  int count = 0;
  for(int i=0; i<10; i++) {
    paintLoadingBar(i);
    lcdController->cleanRow(0);
    lcdController->cleanRow(1);
    paintFishBank(3-i);
    count = count +1;
    delay(500);
  }
}

void WelcomeScreenController::paintLoadingBar(int percentaje) {
  int column = 2;
  lcdController->writeCharacter(0, column, 3);

  for(int i=1; i<10; i++) {
    if(i!= 9 && i <= percentaje) {
      lcdController->writeCharacter(1, column+i, 3);
    } else if(i != 9 && i > percentaje) {
      lcdController->writeCharacter(2, column+i, 3);
    } else if(i == 9 && percentaje == 9) {
      lcdController->writeCharacter(4, column+i, 3);
    } else {
      lcdController->writeCharacter(3, column+i, 3);
    }
  }

  int percentajeInt = (percentaje+1) * 10;
  if(percentaje == 9) {
    lcdController->printText(14, 3, String(percentajeInt) + "%");
  } else {
    lcdController->printText(15, 3, String(percentajeInt) + "%");
  }

}
