#define Buzzer_Pin PA0   //Define Buzzer Pin

void setup() {
  pinMode(Buzzer_Pin, OUTPUT); //Set Buzzer pin as Output
  digitalWrite(Buzzer_Pin, LOW); //Turn off the Buzzer initially
  delay(100);
}

void loop() {
  digitalWrite(Buzzer_Pin, HIGH);  //Turn ON the Buzzer
  delay(1200);
  digitalWrite(Buzzer_Pin, LOW);  //Turn OFF the Buzzer
  delay(1200);
}