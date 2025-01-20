#include <Arduino.h>
#include <Period.h>

static void on_period100(void* instance);

//Parameters are:
//1. Calling instance
//2. Period
//3. Periodic = true, On demand = false
//4. Callback function.
Period period100(NULL, 100, true, on_period100);

void setup() {
  Serial.begin(115200);
}
void loop() {
  period100.Check(millis());
}
void on_period100(void* instance) {
  Serial.println(millis());
}
