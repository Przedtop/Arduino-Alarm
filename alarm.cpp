#include <Arduino.h>
#include "alarm.h"
#include "pinConfig.h"

bool alarmTrigger = false;
bool alarmEnabled = true;

long buttonDelay = 500;
long lastButtonPress_alarmDiable = 0;
long lastButtonPress_alarmTrigger = 0;

void alarmDisable() {
  if (digitalRead(button_alarmDisable) == LOW && millis() - lastButtonPress_alarmDiable > buttonDelay) {
    alarmEnabled = !alarmEnabled;
    alarmTrigger = false;
    lastButtonPress_alarmDiable = millis();
  }
  if (digitalRead(button_alarmTriggerDisable) == LOW && millis() - lastButtonPress_alarmTrigger > buttonDelay) {
    alarmTrigger = false;
    lastButtonPress_alarmTrigger = millis();
  }

  if(alarmEnabled){
    digitalWrite(diode_alarmDisable, LOW);}
  else {
    digitalWrite(diode_alarmDisable, HIGH);
  }
}

void alarm() {
    alarmDisable();
    if(!alarmEnabled){
        return;
    }

    if(digitalRead(detector_infrared) == LOW && alarmTrigger == false) {
        alarmTrigger = true;
    }

    if(alarmTrigger){
        digitalWrite(diode_alarmTrigger, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(diode_alarmTrigger, LOW);
        digitalWrite(buzzer, LOW);
        delay(200);
    } else {
        digitalWrite(diode_alarmTrigger, LOW);
        digitalWrite(buzzer, LOW);
    }
}
