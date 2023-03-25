/* 
           ___________________________________________________________________
           *** {==[=======> (MANEJO DEL I2C CON PANTALLA LCD) <=======]==} ***
           ___________________________________________________________________
*/
/*
Board I2C / TWI pins
Uno       =   A4 (SDA), A5 (SCL)
Mega2560  =   20 (SDA), 21 (SCL)
Leonardo  =   2 (SDA), 3 (SCL)
Due       =   20 (SDA), 21 (SCL), SDA1, SCL1
esta configuracion de  pines se encuentran dentro de la librería "wire": https://www.arduino.cc/en/Reference/Wire
 */
 //Descargar Librería Liquid Crystal_I2C:https://github.com/Corvus-DDoSKrom/Arduino-LCD_I2C/blob/main/LiquidCrystal_I2C.zip
 //Direcciones de LCD (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print(" ==> Corvus <=="); 
  lcd.setCursor (0,1);
  lcd.print("==> DDoSKrom <==");
}
void loop() { 
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}