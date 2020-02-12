#include "LightsController.h"

LightsController::LightsController(){

}

void LightsController::turnOnLights() {
  digitalWrite(LIGHTS_PIN, HIGH);
}

void LightsController::turnOffLights() {
  digitalWrite(LIGHTS_PIN, LOW);
}

int LightsController::lightsStatus() {
  return digitalRead(LIGHTS_PIN);
}
