#ifndef ShowMainScreenInyector_h
#define ShowMainScreenInyector_h

#include "../core/CoreInyector.h"
#include "domain/ShowMainScreenUseCase.h"

class ShowMainScreenInyector: public CoreInyector {
public:
  ShowMainScreenInyector();
  MainScreenController* getMainScreenController();
  ShowMainScreenUseCase* getShowMainScreenUseCase();

private:
  static ShowMainScreenUseCase* useCaseInstance;
  GetTimeController* getTimeController();

};


#endif
