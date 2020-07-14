#ifndef JoystickController_h
#define JoystickController_h

#include "Arduino.h"

#define VRY_PIN A2
#define BUTTON_PIN 9
#define UP 0
#define DOWN 1
#define MIDDLE -1


class JoystickController {

public:
  JoystickController();
  boolean wasButtonPressed();
  boolean wasSwipeRight();
  boolean wasSwipedLeft();

private:



};

#endif
