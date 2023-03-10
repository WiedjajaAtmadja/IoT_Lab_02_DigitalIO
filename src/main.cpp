/*
Simple DigitalIO: 
  - Detect the state of a button and turn on/off a LED

JTAG Pin
TMS: GIO14
TDI: GPIO12
TCKL: GPIO13
TDO: GPIO15
  
*/
#include <Arduino.h>
#define PIN_SWITCH 23
int nCount = 0;
void setup() {
  uint32_t chipId = 0;

  pinMode(PIN_SWITCH, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  for(int i=0; i<17; i=i+8) {
	  chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}
  Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
  Serial.printf("This chip runs at %d MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("This chip has flash size of %d MBytes\n", ESP.getFlashChipSize() / (1024 * 1024));
  // print flash speed
  Serial.printf("This chip has flash speed of %d Mhz\n", ESP.getFlashChipSpeed() / 1000000);
	Serial.printf("This chip has %d cores\n", ESP.getChipCores());
  Serial.print("Chip ID: "); Serial.println(chipId);
  // print memory size
  Serial.printf("Total heap: %d\n", ESP.getHeapSize());
  // print free heap
  Serial.printf("Free heap : %d\n", ESP.getFreeHeap());
  // print ESP32 SDK version
  Serial.printf("ESP32 SDK version: %s\n", ESP.getSdkVersion());

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