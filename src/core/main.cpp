#include <Arduino.h>
#include "action/ActionHandler.h"

ActionHandler* actionHandler;
JoystickController* joystickController;

void setup() {
  Serial.begin(9600);
  delay(1000);
  actionHandler = new ActionHandler();
  joystickController = new JoystickController();
  actionHandler->start(3000);
  actionHandler->executeAction("S_W");
  delay(1000);
  actionHandler->executeAction("R_A:First alert");
  delay(1000);
  actionHandler->executeAction("R_A:Second alert");
  delay(1000);
  actionHandler->executeAction("R_A:Third alert");
  delay(1000);
}

void displayMenuIfNeeded() {
  if(joystickController->wasButtonPressed()) {
    actionHandler->executeAction("S_A");
  }
}

void loop() {
  VariableTimedAction::updateActions();
  displayMenuIfNeeded();
}
