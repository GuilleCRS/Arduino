#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
double arr[20] = {};
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
boolean bandera=false;
int trigger=9;
int echo=8;
double duracion, cm,alturaRec=18.35,radio=9.5,volumen,volumen2;

void setup() {
  // Se inicializan las columnas y filas del lcd
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
 lcd.home();
  volumen=PI*radio*radio*alturaRec;
  double promedio=0;
  for(int i=0;i<=20;i++){
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    duracion = pulseIn(echo, HIGH);
    cm = (duracion/2) * 0.034;
    Serial.println(cm);
    if(cm<alturaRec){
      arr[i]=cm; 
    }else{bandera=true;}
  }
  double cm2 = getEP(arr) ;
  if(bandera){
    cm=alturaRec;
    cm2=alturaRec;
  }
  volumen2=PI*radio*radio*cm2;
  double porcentaje=volumen2/volumen;
  lcd.print(100-(porcentaje*100));lcd.print(" %       ");
  lcd.setCursor(0,1);
  lcd.print(volumen-volumen2);lcd.print(" ml          ");
  delay(10 );
  promedio=0;
  bandera=false;
}


double getEP(double a[])
{
  int contador = 1, contTemp;
  double popular = a[0];
  double temp = 0;
  for (int i = 0; i < (sizeof(a)/sizeof(double) - 1); i++)
  {
    temp = a[i];
    contTemp = 0;
    for (int j = 1; j < sizeof(a)/sizeof(double); j++)
    {
      if (temp == a[j])
        contTemp++;
    }
    if (contTemp > contador)
    {
      popular = temp;
      contador = contTemp;
    }
  }
  return popular;
}
