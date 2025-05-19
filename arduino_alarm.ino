#include <Arduino.h>
#include "pinConfig.h"
#include "alarm.h"

void setup() {
    pinMode(button_alarmDisable, INPUT_PULLUP);
    pinMode(button_alarmTriggerDisable, INPUT_PULLUP);
    pinMode(alarmTrigger_diode_buzzer, OUTPUT);
    pinMode(diode_alarmDisable, OUTPUT);
    pinMode(a_display , OUTPUT);
    pinMode(b_display , OUTPUT);
    pinMode(c_display , OUTPUT);
    pinMode(d_display , OUTPUT);
    pinMode(e_display , OUTPUT);
    pinMode(f_display , OUTPUT);
    pinMode(g_display , OUTPUT);
    Serial.begin(9600);
}

void loop() {
    alarm();
}
