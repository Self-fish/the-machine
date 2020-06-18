#include "JoystickController.h"


JoystickController::JoystickController() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


boolean JoystickController::wasButtonPressed() {
  if(digitalRead(BUTTON_PIN) == 0) {
    return true;
  } else {
    return false;
  }
}

int JoystickController::readX() {
int value = analogRead(VRY_PIN);
  Serial.println(value);
  if(value > 200) {
    return DOWN;
  } else if(value < 10) {
    return UP;
  } else {
    return MIDDLE;
  }
}
