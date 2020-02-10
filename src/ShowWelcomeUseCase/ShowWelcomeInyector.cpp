#include "ShowWelcomeInyector.h"

ShowWelcomeAction* ShowWelcomeInyector::actionInstance = 0;

ShowWelcomeInyector::ShowWelcomeInyector() {}

ShowWelcomeAction* ShowWelcomeInyector::getShowWelcomeAction() {
  if(actionInstance == 0) {
    actionInstance = new ShowWelcomeAction(getShowWelcomeUseCase(),
      getUsbController());
  }
  return actionInstance;
}

ShowWelcomeUseCase* ShowWelcomeInyector::getShowWelcomeUseCase() {
  return new ShowWelcomeUseCase(getWelcomeScreenController());
}

WelcomeScreenController* ShowWelcomeInyector::getWelcomeScreenController() {
  return new WelcomeScreenController(getLCDController(), getCurrentStatusController());
}
