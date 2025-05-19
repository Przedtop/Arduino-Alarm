#include <Arduino.h>
#include "alarm.h"
#include "pinConfig.h"

void displayNumber(int number);
void alarmDisable();
void countActivations();

bool alarmTrigger = false;
bool alarmEnabled = true;
int activations = 0;

long buttonDelay = 500;
long lastButtonPress_alarmDiable = 0;
long lastButtonPress_alarmTrigger = 0;

void alarm() {
    alarmDisable();
    if(!alarmEnabled){
        return;
    }
    if(digitalRead(detector_infrared) == LOW && alarmTrigger == false) {
        alarmTrigger = true;
    }
    if(alarmTrigger){
        digitalWrite(alarmTrigger_diode_buzzer, HIGH);
        delay(200);
        digitalWrite(alarmTrigger_diode_buzzer, LOW);
        delay(200);
    } else {
        digitalWrite(alarmTrigger_diode_buzzer, LOW);
    }
    countActivations();
     displayNumber(activations);
}

void alarmDisable() {
   if (digitalRead(button_alarmDisable) == LOW && millis() - lastButtonPress_alarmDiable > buttonDelay) {
     alarmEnabled = !alarmEnabled;
     alarmTrigger = false;
     activations = 0;
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

bool triggerRegistered = false;
void countActivations() {
    if(alarmTrigger){
        if(!triggerRegistered){
            activations++;
            triggerRegistered = true;
        }
    }
    else{
        triggerRegistered = false;
    }
   if (activations > 9) {
       activations = 0;
       Serial.println("Alarm triggered 9 times, resetting count");
   }
}

void displayNumber(int number) {
  if(number < 0 || number > 9) {
    Serial.println("Invalid number for display");
    return;
  }
  switch (number) {
    case 0:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , HIGH);
      digitalWrite(f_display , LOW);
      digitalWrite(g_display , HIGH);
      break;

    case 1:
      digitalWrite(a_display , LOW);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , LOW);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , LOW);
      digitalWrite(g_display , LOW);
      break;

    case 2:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , LOW);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , HIGH);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , LOW);
      break;

    case 3:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , LOW);
      break;

    case 4:
      digitalWrite(a_display , LOW);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , LOW);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , HIGH);
      break;

    case 5:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , LOW);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , HIGH);
      break;

    case 6:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , LOW);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , HIGH);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , HIGH);
      break;

    case 7:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , LOW);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , LOW);
      digitalWrite(g_display , LOW);
      break;

    case 8:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , HIGH);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , HIGH);
      break;

    case 9:
      digitalWrite(a_display , HIGH);
      digitalWrite(b_display , HIGH);
      digitalWrite(c_display , HIGH);
      digitalWrite(d_display , HIGH);
      digitalWrite(e_display , LOW);
      digitalWrite(f_display , HIGH);
      digitalWrite(g_display , HIGH);
      break;
  }
}