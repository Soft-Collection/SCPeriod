#ifndef SCPeriod_h
#define SCPeriod_h

#include <Arduino.h>

class SCPeriod {
public:
  typedef void (*dlgOnPeriodExpired)();
public:
  SCPeriod(uint32_t periodInMS, bool autoRestart, dlgOnPeriodExpired onPeriodExpired);
  virtual ~SCPeriod();
  void Check();
  void Start();
  bool GetAutoRestart();
  void SetPeriodInMS(uint32_t periodInMS);
private:
  uint32_t mPeriodInMS;
  bool mAutoRestart;
  dlgOnPeriodExpired mOnPeriodExpired;
  uint32_t mStartPeriodMeasuringInMS;
  bool mStartPeriodMeasuringIsSet;
};

#endif  //SCPeriod_h