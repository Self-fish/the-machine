#ifndef HandleAlertsUseCase_h
#define HandleAlertsUseCase_h


class HandleAlertsUseCase {

public:
  HandleAlertsUseCase();
  void showAlert(char* alert);

private:
  void freeResources();
};


#endif
