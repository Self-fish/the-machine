#include <Arduino.h>
#include "action/ActionHandler.h"

ActionHandler* actionHandler;
//JoystickController* joystickController;
//AlertsController* alertsController;

void setup() {
  Serial.begin(9600);
  delay(1000);

  //joystickController = new JoystickController();
  //alertsController = new AlertsController();
  actionHandler = new ActionHandler(/*joystickController*/);
  //actionHandler->start(3000);
  actionHandler->executeAction("S_W");
}

/*void displayMenuIfNeeded() {
  if(joystickController->wasButtonPressed()) {
    actionHandler->executeAction("S_A");
  }
}*/

void loop() {
  //VariableTimedAction::updateActions();
  actionHandler->run();
  /*actionHandler->executeAction("T_U");
  delay(1000);
  actionHandler->executeAction("H_U");
  delay(1000);
  actionHandler->executeAction("W_U");
  delay(1000);
  actionHandler->executeAction("L_G");
  delay(1000);
  actionHandler->executeAction("L_N");
  delay(1000);
  actionHandler->executeAction("R_A:Change 100% water");
  delay(5000);*/
  //displayMenuIfNeeded();
}
