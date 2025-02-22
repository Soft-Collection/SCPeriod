#include <Arduino.h>
#include <SCPeriod.h>

class SCPeriodCallbacks1 : public SCPeriodCallbacks {
  virtual void OnPeriodExpired() {
    Serial.print("Auto ");
    Serial.print(millis());
    Serial.println();
  }
};

class SCPeriodCallbacks2 : public SCPeriodCallbacks {
  virtual void OnPeriodExpired() {
    Serial.print("On demand ");
    Serial.print(millis());
    Serial.println();
  }
};

//Parameters are:
//1. Period in milliseconds
//2. Periodic = true, On demand = false
//3. Instance of Callbacks class
SCPeriod period100MS_auto_restart(100, true, new SCPeriodCallbacks1());
SCPeriod period10000MS_on_demand(10000, false, new SCPeriodCallbacks2());

void setup() {
  Serial.begin(115200);
  period10000MS_on_demand.Start();
}
void loop() {
  //MUST CALL THIS FUNCTIONS IN THE LOOP.
  period100MS_auto_restart.Check();
  period10000MS_on_demand.Check();
}
