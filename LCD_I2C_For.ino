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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

byte Monster[8] = {
0b11111,
0b11111,
0b10101,
0b11011,
0b10001,
0b10101,
0b11111,
0b11111
};

void setup() {
  lcd.init();  // Inicializa el LCD
  lcd.backlight();  // Enciende la luz de fondo del LCD
  lcd.createChar(0, Monster);
}

void loop() {
  // Crea un array de palabras para mostrar en el LCD
  String words[] = {"Hola", "Soy Corvus", "Sigueme en:", "Twitter:"};
  String words2[] = {"Mundo", "DDoSKrom", "", "@corvus_ddoskrom"};
  int num_words = sizeof(words) / sizeof(words[0]);  // Calcula el número de palabras en el array 
  // Muestra una palabra diferente cada 5 segundos
  for (int i = 0; i < num_words; i++) {
    lcd.clear();  // Borra el contenido actual del LCD
    lcd.setCursor(0, 0);
    lcd.print(words[i]);
    lcd.setCursor(15, 0);
	  lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.print(words2[i]);
    delay(3000);  // Espera 3 segundos
  }
}