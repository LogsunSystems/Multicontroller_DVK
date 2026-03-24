#include <Arduino.h>

#define PIR_PIN 14

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR_PIN,INPUT);

  Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PIR_PIN)){
    Serial.println("Motion Detected !!!");
    delay(1000);
  }
  else{
    Serial.println("No Motion !!!");
    delay(1000);
  }
}