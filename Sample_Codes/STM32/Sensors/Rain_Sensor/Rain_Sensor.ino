
#define RAIN_PIN PA0  //Define the Snsor PIN

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600); // ESP8266 default baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int rain = analogRead(RAIN_PIN); //Read the sensor
  // Tiny JSON payload (to save memory)
  String payload = "{\"Rain\":" + String(rain)  + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);
}
