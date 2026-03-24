#include "DHT.h"
#include "SoftwareSerial.h"
//#include <string.h>

#define TIMEOUT 5000
#define VIBRATION_PIN A0

SoftwareSerial esp(3, 2); // RX, TX

int Buff[10]={0};
bool Flag_VIB = false;

unsigned long CurrentMillis =0;

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  
  memset(Buff, 0, sizeof(Buff));
  Flag_VIB = false;
  int Vibration = analogRead(VIBRATION_PIN);
  for(int i=0;i<10;i++)
  {
    Buff[i]=analogRead(VIBRATION_PIN);
    if(Buff[i]<599)
    {
      Flag_VIB = true;
    }
    delay(500);
  }
  

  if(millis()-CurrentMillis>TIMEOUT)
  {
    String payload = "{\"Vibration\":" + String(Flag_VIB) + "}";
    Serial.println(payload);
    esp.println(payload);
    CurrentMillis = millis();
  }
  
  //delay(300);
}

