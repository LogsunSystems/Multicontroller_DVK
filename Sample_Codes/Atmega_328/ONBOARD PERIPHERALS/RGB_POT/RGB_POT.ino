
#define RED     9
#define GREEN   10
#define BLUE    11

#define POT_1   A0 
#define POT_2   A1 
#define POT_3   A2 

uint16_t red, green, blue, raw_1, raw_2, raw_3;

void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);

  // analogReadResolution(12);
  // analogSetAttenuation(ADC_11db);

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