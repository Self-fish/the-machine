#ifndef ShowBoxHumidityUseCase_h
#define ShowBoxHumidityUseCase_h

#include "../controller/ReadHumidityController.h"
#include "../controller/BoxHumidityScreenController.h"
#include "../../core/controller/UsbController.h"

class ShowBoxHumidityUseCase {

public:
  ShowBoxHumidityUseCase(
    ReadHumidityController* hController, BoxHumidityScreenController* sController);
  void printHumidity();

private:
  ReadHumidityController* humidityController;
  BoxHumidityScreenController* screenController;
  void roundHumidity(double humidity, char* result);
};


#endif
