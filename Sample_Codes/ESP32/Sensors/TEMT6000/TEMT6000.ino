#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>



// WiFi credentials
const char* ssid = "Logsun";
const char* password = "12345678";

// ThingsBoard MQTT broker details
#define THINGSBOARD_SERVER "demo.thingsboard.io" // Cloud instance
// #define THINGSBOARD_SERVER "YOUR_LOCAL_IP" // For local installation
#define TOKEN "bPvLvZYFY3fWknzLPhB1" // From ThingsBoard device dashboard


WiFiClient espClient;
PubSubClient client(espClient);

#define TEMT6000 GPIO_NUM_33
#define ADC_REF 3.3f
#define ADC_MAX 4096.0f
#define SHUNT_RES 10000.0f

String JSON_Data = "";


void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect("ESP32Client", TOKEN, NULL)) {
      Serial.println("Connected to ThingsBoard!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  setup_wifi();
  client.setServer(THINGSBOARD_SERVER, 1883); // MQTT default port
  
  JSON_Data.clear();
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void loop()
{
  StaticJsonDocument<200>  doc;

  float volts = analogRead(TEMT6000) * ADC_REF / ADC_MAX;
  Serial.println(analogRead(TEMT6000));
  float amps = volts / SHUNT_RES;
  float microamps = amps * 1000000;
  float lux = microamps * 2.0;

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  doc["Sensor_Type"] = "Light";
  doc["Sensor"] = "TEMT6000";
  doc["Lux"] = lux;


  serializeJson(doc, JSON_Data);

  // Publish to ThingsBoard
  client.publish("v1/devices/me/telemetry", JSON_Data.c_str());
  //Serial.print("Sensor Data: ");
  //Serial.println(analogRead(TEMT6000));
  Serial.println(JSON_Data);
  JSON_Data.clear();
  delay(5307);
}
