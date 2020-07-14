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

boolean JoystickController::wasSwipeRight() {
  if(analogRead(VRY_PIN) < 100) {
    return true;
  } else {
    return false;
  }
}


boolean JoystickController::wasSwipedLeft() {
  if(analogRead(VRY_PIN) > 900) {
    return true;
  } else {
    return false;
  }
}
