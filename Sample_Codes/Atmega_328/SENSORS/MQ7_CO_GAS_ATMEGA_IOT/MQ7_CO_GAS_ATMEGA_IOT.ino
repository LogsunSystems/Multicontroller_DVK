#include "DHT.h"
#include "SoftwareSerial.h"


#define MQ7_PIN A0

SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
  
  
}

void loop() {
  
  int MQ7 = analogRead(MQ7_PIN);
  String payload = "{\"MQ7\":" + String(MQ7) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(1000);
}

