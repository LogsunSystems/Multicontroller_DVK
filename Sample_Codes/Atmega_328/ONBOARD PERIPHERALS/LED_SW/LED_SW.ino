#define LED1  1
#define LED2  2
#define LED3  3
#define LED4  A5
#define LED5  A4
#define LED6  A2
#define LED7  A1
#define LED8  A0

#define SW1   4
#define SW3   6
#define SW4   7
#define SW2   5
#define SW5   8
#define SW6   12
#define SW7   9
#define SW8   A3


void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);

  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
  pinMode(SW4,INPUT);
  pinMode(SW5,INPUT);
  pinMode(SW6,INPUT);
  pinMode(SW7,INPUT);
  pinMode(SW8,INPUT);
}

void loop()
{
  digitalRead(SW1)?digitalWrite(LED1,HIGH):digitalWrite(LED1,LOW);
  digitalRead(SW2)?digitalWrite(LED2,HIGH):digitalWrite(LED2,LOW);
  digitalRead(SW3)?digitalWrite(LED3,HIGH):digitalWrite(LED3,LOW);
  digitalRead(SW4)?digitalWrite(LED4,HIGH):digitalWrite(LED4,LOW);
  digitalRead(SW5)?digitalWrite(LED5,HIGH):digitalWrite(LED5,LOW);
  digitalRead(SW6)?digitalWrite(LED6,HIGH):digitalWrite(LED6,LOW);
  digitalRead(SW7)?digitalWrite(LED7,HIGH):digitalWrite(LED7,LOW);
  digitalRead(SW8)?digitalWrite(LED8,HIGH):digitalWrite(LED8,LOW);

}