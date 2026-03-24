#include "SoftwareSerial.h"

// Define hall sensor PIN
#define hallSensorPin A0


SoftwareSerial esp(3, 2);  // RX, TX
int hallEffectVal;

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
  delay(100);
}

void loop() {
  hallEffectVal = digitalRead(hallSensorPin);
  String payload = "{\"Hall\":" + String(hallEffectVal) + "}";
  esp.println(payload);
  Serial.println(payload);
  delay(5000);
}

