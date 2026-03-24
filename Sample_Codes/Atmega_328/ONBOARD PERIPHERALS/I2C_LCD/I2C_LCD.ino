 
 //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library  
 #include <Wire.h> //This library allows you to communicate with I2C devices  
 //SDA -> GP4 and SCL -> GP5    
 #include <LiquidCrystal_I2C.h> //  This library is for character LCDs based on the HD44780 controller connected via I2C bus using the cheap I2C backpack modules based on the PCF8574 
 LiquidCrystal_I2C lcd(0x38,16,2);  

 void setup()  
  {  
   lcd.begin();    //initialize lcd screen   
   lcd.backlight();  // turn on the backlight
   lcd.setCursor(0,0);  
   lcd.print("   Welcome to  ");  
   lcd.setCursor(0,1);  
   lcd.print("Logsun Systems");  
   delay(3000);
  }  
 void loop()   
  {  

  }  
