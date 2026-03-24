
#define IR_PIN A0

void setup()
{
  pinMode(IR_PIN,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalRead(IR_PIN)?Serial.println("Obstacle Detected"):Serial.println("No Obstacle");
  delay(800);
}
