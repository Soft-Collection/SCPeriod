#if !defined(__PERIOD_H__)
#define __PERIOD_H__

#include <Arduino.h>

class Period {
public:
  typedef void (*dlgOnPeriodExpired)(void* instance);
public:
  Period(void* instance, uint32_t periodInMS, bool autoRestart, dlgOnPeriodExpired onPeriodExpired);
  virtual ~Period();
  void Check();
  void Start();
  bool GetAutoRestart();
  void SetPeriodInMS(uint32_t periodInMS);
private:
  uint32_t mPeriodInMS;
  bool mAutoRestart;
  //-----------------------------------
  void* mInstance;
  dlgOnPeriodExpired mOnPeriodExpired;
  //-----------------------------------
  uint32_t mStartPeriodMeasuringInMS;
  bool mStartPeriodMeasuringIsSet;
};

#endif  // !defined(__PERIOD_H__)