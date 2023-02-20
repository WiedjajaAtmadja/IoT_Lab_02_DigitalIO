#include <Arduino.h>
#define PIN_SWITCH 23
int nCount =0;
volatile bool fCounterUpdated = false;

IRAM_ATTR void onSwitchPressed() 
{ 
  nCount++; 
  fCounterUpdated = true;
}

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(PIN_SWITCH, INPUT);
 attachInterrupt(digitalPinToInterrupt(PIN_SWITCH), onSwitchPressed, FALLING);
 Serial.begin(115200);
}

int nLedState=HIGH;

void loop() {
  // put your main code here, to run repeatedly:
  // if(digitalRead(PIN_SWITCH) == LOW){
  //   while (digitalRead(PIN_SWITCH) == LOW); 
    
  //   nCount++;
  //   Serial.printf("Count: %d\n", nCount);
  // }

  if (fCounterUpdated) {
    Serial.printf("Count: %d\n", nCount);
    fCounterUpdated = false;
  }
  
  if (millis() % 1000 == 0) {
    digitalWrite(LED_BUILTIN, nLedState);
    nLedState=!nLedState;
  }

  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);
}