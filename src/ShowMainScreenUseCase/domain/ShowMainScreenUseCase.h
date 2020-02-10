#ifndef ShowMainScreenUseCase_h
#define ShowMainScreenUseCase_h

#include "../controller/MainScreenController.h"
#include "../controller/GetTimeController.h"

class ShowMainScreenUseCase {

public:
  ShowMainScreenUseCase(MainScreenController* lController,
    GetTimeController* tController);
  void showScreen();

private:
  MainScreenController* mainScreenController;
  GetTimeController* timeController;

};


#endif
