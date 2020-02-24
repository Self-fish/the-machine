#ifndef ShowWaterTemperatureUseCase_h
#define ShowWaterTemperatureUseCase_h

#include "../controller/ReadWaterTemperatureController.h"
#include "../controller/WaterTemperatureScreenController.h"
#include "../../core/controller/UsbController.h"

class ShowWaterTemperatureUseCase {

public:
  ShowWaterTemperatureUseCase(
    ReadWaterTemperatureController* tController, WaterTemperatureScreenController* sController);
  void printWaterTemperature();

private:
  ReadWaterTemperatureController* temperatureController;
  WaterTemperatureScreenController* screenController;
  void roundTemperature(double temperature, char* result);
  void freeResources();
};


#endif
