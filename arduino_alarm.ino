#include <Arduino.h>
#include "pinConfig.h"
#include "alarm.h"

void setup() {
  pinMode(button_alarmDisable, INPUT_PULLUP);
  pinMode(button_alarmTriggerDisable, INPUT_PULLUP);
  pinMode(diode_alarmTrigger, OUTPUT);
  pinMode(diode_alarmDisable, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  alarm();
}
