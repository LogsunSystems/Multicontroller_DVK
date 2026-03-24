//LCD 8 BIT
//GP3 = J10
//GP2 = J9

#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
//LiquidCrystal lcd(PB0, PB1, PB6, PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7);  /* For 8-bit mode */
LiquidCrystal lcd(4, 5, 6, 8, 12, 13, 17);   /* For 4-bit mode [RS, RW, EN, D4, D5,D6, D7] */

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */

void setup() {
  lcd.begin(16,2);          /* Initialize 16x2 LCD */
  lcd.clear();            /* Clear the LCD */
  lcd.createChar(0, Character1);  /* Generate custom character */
  lcd.createChar(1, Character2);
}

void loop() {
  lcd.setCursor(0,0);       /* Set cursor to column 0 row 0 */
  lcd.print("Welcome to ");     /* Print data on display */
  lcd.setCursor(0,1);  
  lcd.print("Logsun System");       /* Write a character to display */
  //lcd.write(1);
}
