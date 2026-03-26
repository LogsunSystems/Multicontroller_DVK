int relay_1 = 16;
int relay_2 = 17;
int buzzer = 33;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
