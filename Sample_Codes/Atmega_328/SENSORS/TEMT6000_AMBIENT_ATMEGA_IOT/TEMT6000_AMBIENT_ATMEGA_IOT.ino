#include "DHT.h"
#include "SoftwareSerial.h"


#define TEMT6K_PIN A0
#define GET_LIGHT(X)   (X*0.0976f)

SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  
  int Sensor = analogRead(TEMT6K_PIN);
  float light = GET_LIGHT(Sensor);
  String payload = "{\"Lux\":" + String(light) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(5000);
}
