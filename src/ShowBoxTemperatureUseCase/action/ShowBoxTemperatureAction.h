#ifndef ShowBoxTemperatureAction_h
#define ShowBoxTemperatureAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowBoxTemperatureUseCase.h"
#include "../../ShowMainScreenUseCase/domain/ShowMainScreenUseCase.h"

const char UPDATE_TEMPERATURE_ACTION[4] = "T_U";

class ShowBoxTemperatureAction: public Action {

public:
  ShowBoxTemperatureAction(ShowBoxTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowBoxTemperatureUseCase* temperatureUseCase;
  ShowMainScreenUseCase* mainScreenUseCase;
  void freeResources();
};


#endif
