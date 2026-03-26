#define LM35_PIn  33

#define ADC_MAX   4095
#define V_REF     3.3f

#define VOLTAGE_TO_TEMP(X)    (X*100.0)

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int Raw = analogRead(LM35_PIn);
  float Voltage = (float(Raw)/ADC_MAX)*V_REF;
  float Temp = VOLTAGE_TO_TEMP(Voltage);

 
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.println("ºC");

  delay(1000);
  
}