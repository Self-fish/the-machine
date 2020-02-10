#ifndef ShowWaterTemperatureAction_h
#define ShowWaterTemperatureAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowWaterTemperatureUseCase.h"
#include "../../ShowMainScreenUseCase/domain/ShowMainScreenUseCase.h"

class ShowWaterTemperatureAction: public Action {
public:
  ShowWaterTemperatureAction(ShowWaterTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowWaterTemperatureUseCase* temperatureUseCase;
  ShowMainScreenUseCase* mainScreenUseCase;
};


#endif
