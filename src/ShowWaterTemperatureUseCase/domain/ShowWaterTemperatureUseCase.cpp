#include "ShowWaterTemperatureUseCase.h"

ShowWaterTemperatureUseCase::ShowWaterTemperatureUseCase(
    ReadWaterTemperatureController* tController,
    WaterTemperatureScreenController* sController){
  temperatureController = tController;
  screenController = sController;

}

void ShowWaterTemperatureUseCase::printWaterTemperature() {
  char* temperature = (char*)malloc(40);
  roundTemperature(temperatureController->readTemperature(), temperature);
  screenController->configureSpecialCharacters();
  screenController->printWaterTemperature(temperature);
  free(temperature);
}

void ShowWaterTemperatureUseCase::roundTemperature(double humidity, char* result) {
  dtostrf(humidity, 3, 1, result);
}
