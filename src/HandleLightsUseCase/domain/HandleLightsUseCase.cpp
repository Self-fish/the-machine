#include "HandleLightsUseCase.h"

HandleLightsUseCase::HandleLightsUseCase(LightsController* lController) {
  lightsController = lController;
}

void HandleLightsUseCase::turnOnLights() {
  lightsController->turnOnLights();
}

void HandleLightsUseCase::turnOffLights() {
  lightsController->turnOffLights();
}

boolean HandleLightsUseCase::isLightOn() {
  if(lightsController->lightsStatus() == 1) {
    return true;
  } else {
    return false;
  }
}
