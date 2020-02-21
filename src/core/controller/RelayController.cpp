#include "RelayController.h"

RelayController::RelayController(int pin){
  relayPin = pin;
}

void RelayController::turnOn() {
  digitalWrite(relayPin, LOW);
}

void RelayController::turnOff() {
  digitalWrite(relayPin, HIGH);
}

int RelayController::getValue() {
  return digitalRead(relayPin);
}
