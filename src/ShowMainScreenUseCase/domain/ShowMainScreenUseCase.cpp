#include "ShowMainScreenUseCase.h"

ShowMainScreenUseCase::ShowMainScreenUseCase(MainScreenController* lController,
    GetTimeController* tController){
  mainScreenController = lController;
  timeController = tController;
}

void ShowMainScreenUseCase::showScreen() {
  mainScreenController->configureSpecialCharacters();
  mainScreenController->createScreen();
  mainScreenController->printDate(timeController->getCurrentTime(),
    timeController->getCurrentDate());
  freeResources();
}

void ShowMainScreenUseCase::freeResources() {
  free(mainScreenController);
  free(timeController);
}
