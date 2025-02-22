#ifndef SCPeriod_h
#define SCPeriod_h

#include <Arduino.h>

class SCPeriodCallbacks {
public:
  SCPeriodCallbacks(){}
  virtual ~SCPeriodCallbacks(){}
  virtual void OnPeriodExpired(){}
};

class SCPeriod {
public:
  SCPeriod(uint32_t periodInMS, bool autoRestart, SCPeriodCallbacks* callbacks);
  virtual ~SCPeriod();
  void Check();
  void Start();
  bool GetAutoRestart();
  void SetPeriodInMS(uint32_t periodInMS);
private:
  uint32_t mPeriodInMS;
  bool mAutoRestart;
  SCPeriodCallbacks* mCallbacks;
  uint32_t mStartPeriodMeasuringInMS;
  bool mStartPeriodMeasuringIsSet;
};

#endif  //SCPeriod_h