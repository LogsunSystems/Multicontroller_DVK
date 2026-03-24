#include "DHT.h"


#define DHTPIN PA0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); // constructor to declare our sensor


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600); // ESP8266 default baud rate


}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = 25.0;
  float humidity = 50.0;
  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Tiny JSON payload (to save memory)
  String payload = "{\"Temp\":" + String(temperature) + ",\"Humi\":" + String(humidity) + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);
}
