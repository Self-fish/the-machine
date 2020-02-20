#include "LightsController.h"

LightsController::LightsController(){}

void LightsController::turnOnLights() {
  digitalWrite(LIGHTS_PIN, LOW);
}

void LightsController::turnOffLights() {
  digitalWrite(LIGHTS_PIN, HIGH);
}

int LightsController::lightsStatus() {
  return digitalRead(LIGHTS_PIN);
}
