#include "SCPeriod.h"

#define TIME_NOT_SET -1

SCPeriod::SCPeriod(uint32_t periodInMS, bool autoRestart, SCPeriodCallbacks* callbacks) {
  mPeriodInMS = periodInMS;
  mAutoRestart = autoRestart;
  mCallbacks = callbacks;
  mStartPeriodMeasuringInMS = (mAutoRestart) ? millis() : TIME_NOT_SET;
  mStartPeriodMeasuringIsSet = mAutoRestart;
}
SCPeriod::~SCPeriod() {
}
void SCPeriod::Check() {
  uint32_t ms = millis();
  if ((ms - mStartPeriodMeasuringInMS > mPeriodInMS) && (mStartPeriodMeasuringIsSet)) {
    mStartPeriodMeasuringInMS = (mAutoRestart) ? ms : TIME_NOT_SET;
    mStartPeriodMeasuringIsSet = mAutoRestart;
    if (mCallbacks) mCallbacks->OnPeriodExpired();
  }
}
void SCPeriod::Start() {
  if (mAutoRestart) return;
  mStartPeriodMeasuringInMS = millis();
  mStartPeriodMeasuringIsSet = true;
}
bool SCPeriod::GetAutoRestart() {
  return (mAutoRestart);
}
void SCPeriod::SetPeriodInMS(uint32_t periodInMS) {
  mPeriodInMS = periodInMS;
}
