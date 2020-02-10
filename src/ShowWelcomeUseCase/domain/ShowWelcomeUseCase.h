#ifndef ShowWelcomeUseCase_h
#define ShowWelcomeUseCase_h

#include "../controller/WelcomeScreenController.h"

class ShowWelcomeUseCase {

public:
  ShowWelcomeUseCase(WelcomeScreenController* lController);
  void showScreen();

private:
  WelcomeScreenController* welcomeScreenController;
};


#endif
