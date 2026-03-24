/*
  Experiment:- Stepper Motor
  Compony:- Logsun Systems Pune
  Date:-19-06-2019
  Programmer:- Rahul Gaud
  Connection:-1)(PORT C --> STEPPER MOTOR EN-I/P Pins (J13))
              2)(PORT F --> STEPPER MOTOR CONTROL Pins (J14))
              SEQUENCE =START=>DEC=>INC=>REV=>STOP
*/
int EN1 = 2;
int EN2 = 3;                                            
int IP1 = 6;
int IP2 = 7;
int IP3 = 8;
int IP4 = 9;

int start = 12;
int rev = 13;
int inc = 20;
int dec = 21;
int stp = 16;

unsigned int count = 5, run = 0, DIR;
void rotation(void);

void setup()
{
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IP1, OUTPUT);
  pinMode(IP2, OUTPUT);
  pinMode(IP3, OUTPUT);
  pinMode(IP4, OUTPUT);

  pinMode(start, INPUT_PULLUP);
  pinMode(rev, INPUT_PULLUP);
  pinMode(inc, INPUT_PULLUP);
  pinMode(dec, INPUT_PULLUP);
  pinMode(stp, INPUT_PULLUP);

  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
  digitalWrite(IP1, LOW);
  digitalWrite(IP2, LOW);
  digitalWrite(IP3, LOW);
  digitalWrite(IP4, LOW);
}

void loop() {
  if (digitalRead(start) == 0)
  {
    DIR = 0;
    digitalWrite(EN1, HIGH);
    digitalWrite(EN2, HIGH);
    count = 6;
    run = 1;
  }
  else if (digitalRead(rev) == 0)
  {
    DIR = 1;
  }
  else if ((digitalRead(inc) == 0) && count > 1)
  {
    count  = count - 0.5;
    delay(1);
  }
  else if ((digitalRead(dec) == 0) && count < 15)
  {
    count  = count + 1;
    delay(1);
  }
  else if (digitalRead(stp) == 0)
  {
    digitalWrite(EN1, LOW);
    digitalWrite(EN2, LOW);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, LOW);
    run = 0;
  }
  if (run == 1)
    rotation();
}

void rotation()
{
  if (DIR == 0)
  {
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, HIGH);
    delay(count);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, LOW);
    delay(count);
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, LOW);
    delay(count);
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, HIGH);
    delay(count);
  }
  if (DIR == 1)
  {
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, LOW);
    delay(count);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, HIGH);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, LOW);
    delay(count);
    digitalWrite(IP1, LOW);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, HIGH);
    digitalWrite(IP4, HIGH);
    delay(count);
    digitalWrite(IP1, HIGH);
    digitalWrite(IP2, LOW);
    digitalWrite(IP3, LOW);
    digitalWrite(IP4, HIGH);
    delay(count);
  }
}
