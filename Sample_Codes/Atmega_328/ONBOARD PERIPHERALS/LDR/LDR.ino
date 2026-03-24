#define LDR_PIN A0

void setup()
{
  Serial.begin(115200);
  
}


void loop()
{
  int LDR = analogRead(LDR_PIN);
  Serial.print("LDR: ");
  Serial.println(LDR);

  int light = map(LDR,25,625,100,0);

  Serial.println("Light: "+String(light)+"%");


  delay(1000);
}