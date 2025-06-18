#include<LiquidCrystal.h>

// Setting (RS,E,D4,D5,D6,D7) for particular pin number
LiquidCrystal lcd(17, 16, 22, 32, 33, 25, 26);

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */
// Define variable c1,c2,c3,r1,r2,r3,r4 and del
int c1 = 13, c2 = 12, c3 = 14, c4 = 27 ;
int r1 = 1, r2 = 15, r3 = 2, r4 = 4;
int del = 600;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, Character1);  /* Generate custom character */
  lcd.createChar(1, Character2);
  lcd.setCursor(0, 0);
  lcd.print("Hello !");
  delay(1000);
  lcd.clear();
  Serial.print("HELLO ");
  Serial.println(" ");

  /* use input pull-up feature of arduino, so that input c1 to c3 remains HIGH in absence input
    signal
  */
  pinMode(c1, INPUT_PULLUP);
  pinMode(c2, INPUT_PULLUP);
  pinMode(c3, INPUT_PULLUP);
  pinMode(c4, INPUT_PULLUP);

  // Set r1,r2,r3,r4 pins to OUTPUT mode
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  lcd.clear();
  lcd.print("Key: ");
}

void loop() {
  // Calling user defined function row1( ), row2( ), row3( ) and row4( ) next to each other
  row1();
  row2();
  row3();
  row4();
}

// Logic to function row1( )
void row1() {
  /* This the same condition we understand in topic 9.2 i.e. one row should be Low and others should be High to distinguish between other rows and to print row 1 data
  */
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);

  /* We know high signal becomes low when it gets a direct path to ground */
  /* Reading state of c1 and checking if it is LOW then print ‘1’ and if c2 is LOW print ‘2’ and if c3 is LOW print ‘3’
  */
  if (digitalRead(c1) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("1"); delay(del);
    Serial.print("1 ");
  }
  else if (digitalRead(c2) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("2"); delay(del);
    Serial.print("2 ");
  }
  else if (digitalRead(c3) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("3"); delay(del);
    Serial.print("3 ");
  }
  else if (digitalRead(c4) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("A"); delay(del);
    Serial.print("A");
  }
  //delay(del);
  /*why do we not set single delay here instead three in if blocks? Because if we give delay in
     if block then delay will executed only if any key has been pressed but if we give delay
     here each time either key pressed or not delay will be executed which slows the
     programming process.
  */
}

/* Similarly as we set logic for row1 we can set logic for other rows.
   Keep row LOW which we want to set logic and others to be HIGH
   But this time we will print ‘4’, ‘5’, ‘6’ on column key pressed instead of ‘1’, ‘2’, ‘3’.
*/
void row2() {
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);

  if (digitalRead(c1) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("4"); delay(del);
    Serial.print("4 ");
  }
  else if (digitalRead(c2) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("5"); delay(del);
    Serial.print("5 ");
  }
  else if (digitalRead(c3) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("6"); delay(del);
    Serial.print("6 ");
  }
  else if (digitalRead(c4) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("B"); delay(del);
    Serial.print("B ");
  }
}

/* In this we will print ‘7’, ‘8’, ‘9’ on column key pressed.
*/
void row3() {
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, LOW);
  digitalWrite(r4, HIGH);

  if (digitalRead(c1) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("7"); delay(del);
    Serial.print("7 ");
  }
  else if (digitalRead(c2) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("8"); delay(del);
    Serial.print("8 ");
  }
  else if (digitalRead(c3) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("9"); delay(del);
    Serial.print("9 ");
  }
  else if (digitalRead(c4) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("C"); delay(del);
    Serial.print("C ");
  }
}
/* In this we will print ‘*’, ‘0’, ‘#’ on column key pressed.
*/
void row4() {
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, LOW);

  if (digitalRead(c1) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("*"); delay(del);
    Serial.print("* ");
  }
  else if (digitalRead(c2) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("0"); delay(del);
    Serial.print("0 ");
  }
  else if (digitalRead(c3) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("#"); delay(del);
    Serial.print("# ");
  }
  else if (digitalRead(c4) == LOW) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print("D"); delay(del);
    Serial.print("D ");
  }
}
