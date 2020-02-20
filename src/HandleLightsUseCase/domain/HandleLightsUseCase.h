#ifndef HandleLightsUseCase_h
#define HandleLightsUseCase_h

#include "../controller/LightsController.h"

class HandleLightsUseCase {

public:
  HandleLightsUseCase(LightsController* lController);
  void turnOnLights();
  void turnOffLights();
  boolean isLightOn();

private:
  LightsController* lightsController;
};


#endif
