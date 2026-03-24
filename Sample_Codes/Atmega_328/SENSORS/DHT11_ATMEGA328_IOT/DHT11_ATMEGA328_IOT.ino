#include "DHT.h"
#include "SoftwareSerial.h"


// DHT
#define DHTPIN 14
#define DHTTYPE DHT11


// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);


SoftwareSerial esp(3, 2); // RX, TX


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  esp.begin(9600);
  dht.begin();
  
}

void loop() {
  Serial.println("Collecting temperature data.");

  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  String payload = "{\"Temp\":" + String(temperature) + ",\"Humi\":" + String(humidity) + "}";
  Serial.println(payload);

  esp.println(payload);
  delay(5000);
}

