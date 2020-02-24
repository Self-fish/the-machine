#ifndef HandleWaterTempAction_h
#define HandleWaterTempAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../../core/controller/RelayController.h"
#include "../../ShowWaterTemperatureUseCase/controller/ReadWaterTemperatureController.h"

#define WATER_TEMP_PIN 8

const char WATER_ON_ACTION[4] = "T_N";
const char WATER_OFF_ACTION[4] = "T_F";
const char WATER_GET_ACTION[4] = "T_G";

class HandleWaterTempAction: public Action {
public:
  HandleWaterTempAction(RelayController* c, UsbController* uController,
    ReadWaterTemperatureController* tempC);
  void executeAction(char* inputString);

private:
  RelayController* controller;
  ReadWaterTemperatureController* tempController;
  void freeResources();
};


#endif
