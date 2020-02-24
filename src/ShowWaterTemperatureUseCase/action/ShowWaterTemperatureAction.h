#ifndef ShowWaterTemperatureAction_h
#define ShowWaterTemperatureAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowWaterTemperatureUseCase.h"
#include "../../ShowMainScreenUseCase/domain/ShowMainScreenUseCase.h"

const char UPDATE_WATER_TEMPERATURE_ACTION[4] = "W_U";

class ShowWaterTemperatureAction: public Action {
public:
  ShowWaterTemperatureAction(ShowWaterTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowWaterTemperatureUseCase* temperatureUseCase;
  ShowMainScreenUseCase* mainScreenUseCase;
  void freeResources();
};


#endif
