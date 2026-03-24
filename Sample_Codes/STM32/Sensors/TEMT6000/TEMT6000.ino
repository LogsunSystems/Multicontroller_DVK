
#define LUX_PIN PA0  //Define Sensor Pin
#define ADC_REF 3.3
#define ADC_MAX 4095.0
#define SHUNT_RES 10000

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600);  // ESP8266 default baud rate
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float volts = analogRead(LUX_PIN) * ADC_REF / ADC_MAX; //Calculate sensor output voltage
  float amps = volts / SHUNT_RES; //Calculate current
  float microamps = amps * 1000000; //Convert current to microAmpere
  float lux = microamps * 2.0;  //Conver to LUX

  // Tiny JSON payload (to save memory)
  String payload = "{\"LUX\":" + String(lux) + "}";

  //Serial.println(payload);
  Serial1.print(payload);  //Send to Cloud

  delay(5000);
}
