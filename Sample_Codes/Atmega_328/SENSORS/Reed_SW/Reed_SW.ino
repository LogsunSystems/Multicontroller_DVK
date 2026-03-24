#include "DHT.h"
#include "SoftwareSerial.h"


#define REED_PIN 14

SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
  pinMode(REED_PIN,INPUT);
}

void loop() {
  
  int REED = digitalRead(REED_PIN);
  String payload = "{\"REED_SW\":" + String(REED) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(5000);
}

