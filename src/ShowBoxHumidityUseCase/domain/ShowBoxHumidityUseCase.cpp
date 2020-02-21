#include "ShowBoxHumidityUseCase.h"

ShowBoxHumidityUseCase::ShowBoxHumidityUseCase(
    ReadHumidityController* hController,
    BoxHumidityScreenController* sController){
  humidityController = hController;
  screenController = sController;
}

void ShowBoxHumidityUseCase::printHumidity() {
  screenController->configureSpecialCharacters();
  char* humidity = (char*)malloc(40);
  roundHumidity(humidityController->readHumidity(), humidity);
  screenController->printBoxHumidity(humidity);
  free(humidity);
  freeResources();
}

void ShowBoxHumidityUseCase::roundHumidity(double humidity, char* result) {
  dtostrf(humidity, 3, 1, result);
}

void ShowBoxHumidityUseCase::freeResources() {
  free(humidityController);
  free(screenController);
}
