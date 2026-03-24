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

#define TIMEOUT 5000
#define VIBRATION_PIN A0

int Buff[10]={0};
bool Flag_VIB = false;

unsigned long CurrentMillis =0;


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



void setup() {
  // initialize serial for debugging
  Serial.begin(115200);
  setup_wifi();
  client.setServer(THINGSBOARD_SERVER, 1883); // MQTT default port
  
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
    // Prepare JSON payload
  StaticJsonDocument<200> doc;
  doc["Vibration"] = Distance;
  

  char payload[200];
  serializeJson(doc, payload);

  // Publish to ThingsBoard
  client.publish("v1/devices/me/telemetry", payload);
  Serial.println("Data sent: " + String(payload));
    
    CurrentMillis = millis();
  }
  
}

