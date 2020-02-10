#ifndef ShowWelcomeInyector_h
#define ShowWelcomeInyector_h

#include "action/ShowWelcomeAction.h"
#include "../core/CoreInyector.h"

class ShowWelcomeInyector: public CoreInyector {
public:
  ShowWelcomeInyector();
  ShowWelcomeAction* getShowWelcomeAction();
  WelcomeScreenController* getWelcomeScreenController();

private:
  static ShowWelcomeAction* actionInstance;
  ShowWelcomeUseCase* getShowWelcomeUseCase();
};


#endif
