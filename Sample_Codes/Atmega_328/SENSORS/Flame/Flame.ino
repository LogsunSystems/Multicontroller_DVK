#include "SoftwareSerial.h"

SoftwareSerial WIFI(3,2);
#define FLAME_PIN 14


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  WIFI.begin(9600); // ESP8266 default baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int Fire = digitalRead(FLAME_PIN);
  // Tiny JSON payload (to save memory)
  String payload = "{\"FLAME\":" + String(Fire)  + "}";

  //Serial.println(payload);
  WIFI.print(payload);

  delay(5000);
}
