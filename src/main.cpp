/*
Simple DigitalIO: 
  - Detect the state of a button and turn on/off a LED
*/
#include <Arduino.h>
#define PIN_SWITCH 23
int nCount = 0;
void setup() {
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("System ready");
}

void loop() {
  // if user push the button
  if (digitalRead(PIN_SWITCH) == LOW) {
    nCount++;
    Serial.printf("Button pressed, Count: %d", nCount);
    // wait until the button is released
    while(digitalRead(PIN_SWITCH) == LOW) 
      delay(1);
  } 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}