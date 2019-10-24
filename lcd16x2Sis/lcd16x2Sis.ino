
#include <LiquidCrystal.h>

// incializar pines de interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Establecemos columnas y fias
  lcd.begin(16, 2);
  // Se imprime mensaje por pantalla
  lcd.print("Hola materia sistemas programables");
}

void loop() {
  // 
  // Establecemos el cursor al principio de la segunda fila
  lcd.setCursor(0, 1);
  // imprime el numero de milisegundos desde que se incio
  lcd.print(millis() / 1000);
  lcd.scrollDisplayLeft();
  delay(150);
}
 
