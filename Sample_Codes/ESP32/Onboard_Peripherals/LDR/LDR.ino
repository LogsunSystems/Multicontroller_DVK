#define LDR_PIN A0

void setup()
{
  Serial.begin(115200);
  
}


void loop()
{
  Serial.print("LDR: ");
  Serial.println(analogRead(LDR_PIN));
  delay(1000);
}