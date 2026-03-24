
#define RED     PA5
#define GREEN   PA6
#define BLUE    PA7

#define POT_1   PA1
#define POT_2   PA2
#define POT_3   PA3

uint16_t red, green, blue, raw_1, raw_2, raw_3;

void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);

  
  

  Serial.begin(115200);


}

void loop()
{
  raw_1 = analogRead(POT_1);
  raw_2 = analogRead(POT_2);
  raw_3 = analogRead(POT_3);

 

  red = map(raw_1,0,4095,0,255);
  blue = map(raw_2,0,4095,0,255);
  green = map(raw_3, 0,4095,0,255);

  analogWrite(RED,red);
  analogWrite(BLUE,blue);
  analogWrite(GREEN,green);
  
  delay(30);
}