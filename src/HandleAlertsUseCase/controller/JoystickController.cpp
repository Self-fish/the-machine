#include "JoystickController.h"


JoystickController::JoystickController() {}


boolean JoystickController::wasButtonPressed() {
  if(digitalRead(BUTTON_PIN) == 0) {
    return true;
  } else {
    return false;
  }
}

int JoystickController::readX() {
  if(analogRead(VRY_PIN) > 200) {
    return DOWN;
  } else if(analogRead(VRY_PIN) < 10) {
    return UP;
  } else {
    return MIDDLE;
  }
}
