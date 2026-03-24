
#define RED     10
#define GREEN   11
#define BLUE    12

#define POT_1   26 
#define POT_2   27 
#define POT_3   28 

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