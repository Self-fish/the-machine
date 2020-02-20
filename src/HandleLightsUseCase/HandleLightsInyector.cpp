#include "HandleLightsInyector.h"

HandleLightsAction* HandleLightsInyector::actionInstance = 0;

HandleLightsInyector::HandleLightsInyector() {}

HandleLightsAction* HandleLightsInyector::getHandleLightsAction() {
  if(actionInstance == 0) {
    actionInstance = new HandleLightsAction(getLightsController(),
      getUsbController());
  }
  return actionInstance;
}

LightsController* HandleLightsInyector::getLightsController() {
  return new LightsController();
}
