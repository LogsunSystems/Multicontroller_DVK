#define Relay_Pin PA0   //Define Relay Pin

void setup() {
  pinMode(Relay_Pin, OUTPUT); //Set relay pin as Output
  digitalWrite(Relay_Pin, LOW); //Turn off the relay initially
  delay(100);
}

void loop() {
  digitalWrite(Relay_Pin, HIGH);  //Turn ON the relay
  delay(1200);
  digitalWrite(Relay_Pin, LOW);  //Turn OFF the relay
  delay(1200);
}