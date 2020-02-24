#ifndef ShowBoxTemperatureUseCase_h
#define ShowBoxTemperatureUseCase_h

#include "../controller/ReadTemperatureController.h"
#include "../controller/BoxTemperatureScreenController.h"
#include "../../core/controller/UsbController.h"

class ShowBoxTemperatureUseCase {

public:
  ShowBoxTemperatureUseCase(
    ReadTemperatureController* hController, BoxTemperatureScreenController* sController);
  void printBoxTemperature();

private:
  ReadTemperatureController* temperatureController;
  BoxTemperatureScreenController* screenController;
  void roundTemperature(double humidity, char* result);
  void freeResources();
};


#endif
