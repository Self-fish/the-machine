#ifndef HandleLightsInyector_h
#define HandleLightsInyector_h

#include "action/HandleLightsAction.h"
#include "../core/CoreInyector.h"

class HandleLightsInyector: public CoreInyector {
public:
  HandleLightsInyector();
  HandleLightsAction* getHandleLightsAction();
  LightsController* getLightsController();

private:
  static HandleLightsAction* actionInstance;
  HandleLightsUseCase* getHandleLightsUseCase();
};


#endif
