#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define LDR_PIN 3

// WiFi credentials
const char* ssid = "Logsun";
const char* password = "12345678";

// ThingsBoard MQTT broker details
#define THINGSBOARD_SERVER "demo.thingsboard.io" // Cloud instance
// #define THINGSBOARD_SERVER "YOUR_LOCAL_IP" // For local installation
#define TOKEN "bPvLvZYFY3fWknzLPhB1" // From ThingsBoard device dashboard

WiFiClient espClient;
PubSubClient client(espClient);


int Light = 0;


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
  Serial.println("\r\n\r\n*************LDR Cloud Demo*************\r\n");
  delay(1000);

}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  Light = analogRead(LDR_PIN);

  StaticJsonDocument<200> doc;
  doc["Light"] = Light;
  
  char payload[200];
  serializeJson(doc, payload);

  // Publish to ThingsBoard
  client.publish("v1/devices/me/telemetry", payload);
  Serial.println("Data sent: " + String(payload));

  delay(5000); // Send data every 5 seconds
}