#define LDR_PIN 33

int Light=0,Raw=0;

void setup()
{
  Serial.begin(115200);
  
}


void loop()
{
  Serial.print("LDR: ");
  Raw = analogRead(LDR_PIN);
  Light = map(Raw,0,4095,100,0);
  Serial.println(Light);
  delay(1000);
}