int i = 0;
int Switch_1 = 12;
int Switch_2 = 13;
int Switch_3 = 20;
int Switch_4 = 21;
int Switch_5 = 16;

int SW1;
int SW2;
int SW3;
int SW4;
int SW5;

int IP1 = 6;
int IP2 = 7;
int EN1 = 2;

int motorSpeed = 0;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(EN1, OUTPUT);
  pinMode(IP1, OUTPUT);
  pinMode(IP2, OUTPUT);
  pinMode(Switch_1, INPUT_PULLUP);
  pinMode(Switch_2, INPUT_PULLUP);
  pinMode(Switch_3, INPUT_PULLUP);
  pinMode(Switch_4, INPUT_PULLUP);
  pinMode(Switch_5, INPUT_PULLUP);
}

void loop() {
  SW1 = digitalRead(Switch_1);
  SW2 = digitalRead(Switch_2);
  SW3 = digitalRead(Switch_3);
  SW4 = digitalRead(Switch_4);
  SW5 = digitalRead(Switch_5);
  // put your main code here, to run repeatedly:
  // digitalWrite(IP1, HIGH);
  // digitalWrite(IP2, LOW);
  if (SW1 == 0) {
    
    motorSpeed = 125;
    val = 1;
    analogWrite(EN1, motorSpeed);
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, LOW);
    delay(350);
  }
  if (SW2 == 0) {
    
    motorSpeed = 125;
    val = 1;
    analogWrite(EN1, motorSpeed);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, HIGH);
    delay(350);
  }
  if (SW3 == 0 && val == 1) {
    
    if(motorSpeed <255)
    {
      motorSpeed = motorSpeed + 25;
    }
    else {
    motorSpeed = 255;
    }
    
    analogWrite(EN1, motorSpeed);
    delay(350);
  }
  if (SW4 == 0 && val == 1) {
    
    if(motorSpeed > 50)
    {
      motorSpeed = motorSpeed - 25;
    }
    else {
    motorSpeed = 50;
    }
    
    analogWrite(EN1, motorSpeed);
    delay(350);
  }
  if (SW5 == 0) {
    
    motorSpeed = 0;
    //val = 1;
    analogWrite(EN1, motorSpeed);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, LOW);
    delay(350);
  }
  
}
