#include "DHT.h"
#include "SoftwareSerial.h"


#define MQ6_PIN A0

SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  
  int MQ6 = analogRead(MQ6_PIN);
  String payload = "{\"MQ6\":" + String(MQ6) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(5000);
}

