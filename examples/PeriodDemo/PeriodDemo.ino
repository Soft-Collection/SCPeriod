#include <Arduino.h>
#include <SCPeriod.h>

//Parameters are:
//1. Period
//2. Periodic = true, On demand = false
//3. Callback function.
SCPeriod period100MS_auto_restart(100, true, []() {
  Serial.print("Auto ");
  Serial.print(millis());
  Serial.println();
});
SCPeriod period10000MS_on_demand(10000, false, []() {
  Serial.print("On demand ");
  Serial.print(millis());
  Serial.println();
});

void setup() {
  Serial.begin(115200);
  period10000MS_on_demand.Start();
}
void loop() {
  //MUST CALL THIS FUNCTIONS IN THE LOOP.
  period100MS_auto_restart.Check();
  period10000MS_on_demand.Check();
}
