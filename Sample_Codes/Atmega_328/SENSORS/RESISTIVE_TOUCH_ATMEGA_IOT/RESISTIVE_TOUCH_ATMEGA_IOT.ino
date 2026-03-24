#include "DHT.h"
#include "SoftwareSerial.h"


#define TOUCH_PIN A0

SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
  
  
}

void loop() {
  
  int Touch = analogRead(TOUCH_PIN);
  String payload = "{\"Touch\":" + String(Touch) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(5000);
}

