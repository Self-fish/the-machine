#include "ShowMainScreenInyector.h"

ShowMainScreenUseCase* ShowMainScreenInyector::useCaseInstance = 0;

ShowMainScreenInyector::ShowMainScreenInyector() {}

ShowMainScreenUseCase* ShowMainScreenInyector::getShowMainScreenUseCase() {
  if(useCaseInstance == 0) {
    useCaseInstance = new ShowMainScreenUseCase(getMainScreenController(),
      getTimeController());
  }
  return useCaseInstance;
}

MainScreenController* ShowMainScreenInyector::getMainScreenController() {
  return new MainScreenController(getLCDController(), getCurrentStatusController());
}

GetTimeController* ShowMainScreenInyector::getTimeController() {
  return new GetTimeController();
}
