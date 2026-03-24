#include <SoftwareSerial.h>

SoftwareSerial esp(3,2);

String SSID = "YOUR SSID";  //Replace with Your WiFi Name (SSID)
String PASSWORD = "Your WiFi Password"; // Replace with your Wifi Password
String TOKEN = "Thingsboard Device Token";  //Replace witht your thingsboard device token

void setup()
{
  Serial.begin(9600);
  esp.begin(9600);
  delay(100);

  Serial.println("Configuring WiFi...");

  String payload = "{\"Config\":" + "\"WiFI\"" + ",\"SSID\":" + String(humidity) + "}";
}

void loop()
{



}