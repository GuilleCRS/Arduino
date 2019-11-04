#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
String mensajes[3]={"Hola materia de sistemas programables",
                    "100 y nos vamos !",
                    "Hecho en Arduino Uno y lcd 16x2 + potenciometro"};
int rapidezTxt=250; //velocidad de avanzado caracter por caracter
//Se asignan las variables al constructor de la libreria Liquid Crystal
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String msg[16]={};
boolean bandera=false;

void setup() {
  // Se inicializan las columnas y filas del lcd
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
//Se genera un mensaje random de la lista de mensajes
String mensaje="";

 if(Serial.available()){
  mensaje=Serial.readString();
  delay(5000);
  lcd.print("1");
 }
  mensaje="                "+mensaje;
  for(int tM=0;tM<=mensaje.length();tM++){

      for(int i=0;i<16;i++){
      msg[i]=mensaje.charAt(tM+i);
      lcd.print(msg[i]);
      }
    delay(rapidezTxt);
    lcd.clear();
  }
  lcd.clear();
}
