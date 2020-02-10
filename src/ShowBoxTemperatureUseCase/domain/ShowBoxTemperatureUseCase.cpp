#include "ShowBoxTemperatureUseCase.h"

ShowBoxTemperatureUseCase::ShowBoxTemperatureUseCase(
    ReadTemperatureController* tController,
    BoxTemperatureScreenController* sController){
  temperatureController = tController;
  screenController = sController;

}

void ShowBoxTemperatureUseCase::printBoxTemperature() {
  screenController->configureSpecialCharacters();
  char* temperature = (char*)malloc(40);
  roundTemperature(temperatureController->readTemperature(), temperature);
  screenController->printBoxTemperature(temperature);
  free(temperature);
}

void ShowBoxTemperatureUseCase::roundTemperature(double humidity, char* result) {
  dtostrf(humidity, 3, 1, result);
}
