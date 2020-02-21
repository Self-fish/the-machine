#include "ShowWelcomeUseCase.h"

ShowWelcomeUseCase::ShowWelcomeUseCase(WelcomeScreenController* lController){
  welcomeScreenController = lController;
}

void ShowWelcomeUseCase::showScreen() {
  welcomeScreenController->configureSpecialCharacters();
  welcomeScreenController->printWelcomeMessage();
  delay(1000);
  welcomeScreenController->printLoading();
  freeResources();
}

void ShowWelcomeUseCase::freeResources() {
  free(welcomeScreenController);
}
