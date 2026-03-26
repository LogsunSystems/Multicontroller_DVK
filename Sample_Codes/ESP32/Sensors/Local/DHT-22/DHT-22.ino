#include "DHT.h"
#include <ArduinoJson.h>


#define DHTPIN 33
#define DHTTYPE DHT22

// Sensor variables (example: DHT22)
float temperature = 21.5; // Replace with actual sensor reading
float humidity = 75.0;    // Replace with actual sensor reading

DHT dht(DHTPIN, DHTTYPE); // constructor to declare our sensor


void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("\r\n\r\n*************DHT-11 Cloud Demo*************\r\n");
  delay(1000);
}

void loop() {


  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  Serial.printf("Temperature: %f\r\n",temperature);
  Serial.printf("Humidity: %f\r\n",humidity);

  // Prepare JSON payload
  StaticJsonDocument<200> doc;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;

  char payload[200];
  serializeJson(doc, payload);


  Serial.println("Data sent: " + String(payload));

  delay(5000); // Send data every 5 seconds
}


