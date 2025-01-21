#include <Arduino.h>
#include <SCPeriod.h>

static void on_period100MS_auto_restart(void* instance);
static void on_period10000MS_on_demand(void* instance);

//Parameters are:
//1. Calling instance
//2. Period
//3. Periodic = true, On demand = false
//4. Callback function.
SCPeriod period100MS_auto_restart(NULL, 100, true, on_period100MS_auto_restart);
SCPeriod period10000MS_on_demand(NULL, 10000, false, on_period10000MS_on_demand);

void setup() {
  Serial.begin(115200);
  period10000MS_on_demand.Start();
}
void loop() {
  //MUST CALL THIS FUNCTIONS IN THE LOOP.
  period100MS_auto_restart.Check();
  period10000MS_on_demand.Check();
}
void on_period100MS_auto_restart(void* instance) {
  Serial.print("Auto ");
  Serial.print(millis());
  Serial.println();
}
void on_period10000MS_on_demand(void* instance) {
  Serial.print("On demand ");
  Serial.print(millis());
  Serial.println();
}
