#include "SCPeriod.h"

#define TIME_NOT_SET -1

Period::Period(void* instance, uint32_t periodInMS, bool autoRestart, dlgOnPeriodExpired onPeriodExpired) {
  mPeriodInMS = periodInMS;
  mAutoRestart = autoRestart;
  //--------------------------------------------
  mInstance = instance;
  mOnPeriodExpired = onPeriodExpired;
  //--------------------------------------------
  mStartPeriodMeasuringInMS = (mAutoRestart) ? millis() : TIME_NOT_SET;
  mStartPeriodMeasuringIsSet = mAutoRestart;
}
Period::~Period() {
}
void Period::Check() {
  uint32_t ms = millis();
  if ((ms - mStartPeriodMeasuringInMS > mPeriodInMS) && (mStartPeriodMeasuringIsSet)) {
    mStartPeriodMeasuringInMS = (mAutoRestart) ? ms : TIME_NOT_SET;
    mStartPeriodMeasuringIsSet = mAutoRestart;
    if (mOnPeriodExpired) mOnPeriodExpired(mInstance);
  }
}
void Period::Start() {
  if (mAutoRestart) return;
  mStartPeriodMeasuringInMS = millis();
  mStartPeriodMeasuringIsSet = true;
}
bool Period::GetAutoRestart() {
  return (mAutoRestart);
}
void Period::SetPeriodInMS(uint32_t periodInMS) {
  mPeriodInMS = periodInMS;
}
