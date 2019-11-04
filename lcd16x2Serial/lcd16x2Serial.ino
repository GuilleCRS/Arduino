#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int rapidezTxt=250; //velocidad de avanzado caracter por caracter
//Se asignan las variables al constructor de la libreria Liquid Crystal
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String msg[16]={};
//Variable bandera para el manejo de display de texto arriba y abajo
boolean bandera=false;
String msgEnEspera="";

void setup() {
  // Se inicializan las columnas y filas del lcd
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
lcd.home();
//Se genera un mensaje random de la lista de mensajes
String mensaje="";
//Se agrega 16 caracteres antes del mensaje para comenzar al final del lcd
 if(Serial.available()){
    mensaje=Serial.readString();
    mensaje="                "+mensaje;
 }
 if(mensaje==""){
  String p="....";
  lcd.print("Esperando");
  lcd.setCursor(0,1);
  for(int i=0;i<p.length();i++){
     lcd.print(p.charAt(i));
     delay(150);
  }
 }

  for(int tM=0;tM<=mensaje.length()&&mensaje!="";tM++){
     for(int i=0;i<16;i++){
      lcd.setCursor(0,0);
      lcd.print("Recibido: ");
      lcd.setCursor(i,1);
      msg[i]=mensaje.charAt(tM+i);
      lcd.print(msg[i]);
    }
    delay(rapidezTxt);
    lcd.clear();
  }
  lcd.clear();
}
