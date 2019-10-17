/*  NOMENCLATURA DE INDICES SEMAFORO 1 Y 2
 * led[0]=4 --> Semaforo 1 verde
 * led[1]=5 --> Semaforo 1 vuelta verde
 * led[2]=6 --> Semaforo 1 amarillo/azul
 * led[3]=7 --> Semaforo 1 rojo
 * led[4]=8 --> Semaforo 2 verde
 * led[5]=9 --> Semaforo 2 vuelta verde
 * led[6]=10 --> Semaforo 2 amarillo/azul
 * led[7]=11 --> Semaforo 2 rojo 
*/
int led[]={4,5,6,7,8,9,10,11}; 
int tiempoVerde=5000;                       //Tiempo que dura el led verde previo al cambio de luz y posterior al termino de la vuelta 
int tiempoVuelta=2000;                    //Tiempo el led  vuelta antes de dar el cambio de luz en milisegundos
int tiempoAmarillo=3000;                //Tiempo que dura el amarillo en milisegundos
int tiempoCambio=1000;                    //Tiempo que dura el cambio de luz en miliSegundos
int tiempoPrevioVuelta=2000;              //Tiempo que dura el led previo a encender la vuelta en milisegundos
long duracion, cm;
boolean botonSensor = false;

void setup() {
  pinMode(12,OUTPUT);//Trigger sensor ultrasonico
  pinMode(13,INPUT);//Echo sensor ultrasonico
  pinMode(2,INPUT);//Input boton
 //Se recorren todo el arreglo de leds para inicializar como salida
  for(int i=0;i<8;i++){
    pinMode(led[i],OUTPUT);
    }
}

void loop() {
  //Se hace un chequeo para ver el estado actual del boton
  //Esto se hace en 3 partes del codigo 
  checaBoton();
  //Apaga todos los leds en cada ciclo
  for(int i=0;i<8;i++){
    digitalWrite(led[i],LOW);
   //Se mandan los leds del semaforo 1 para que se haga el manejo correspondiente
  digitalWrite(12, HIGH);//Se manda un pulso con el sensor infrarojo
  delayMicroseconds(10);//Se hace una pequeña pausa de 10 ms mandando la señal 
  digitalWrite(12, LOW);//Se termina la señal
  duracion = pulseIn(13, HIGH);//Se saca el tiempo que duro con el echo del sensor
  cm = (duracion/2) * 0.034;   //Se saca la distancia diviendo la duracion entre 2(ida y vuelta)
  //y se multiplica 0.034 
  //Enciende la vuelta verde del semaforo en cuestion, hace una espera 
  //del tiempo que se desea que dure la vuelta y hace un cambio de luz antes de apagarse
  if(cm<10){
       //Se hace una espera previa a marcar y encender la vuelta declarada en la variable tiempoPrevioVuelta
      manejoLuces(led[0],led[1],led[2],led[3],true);
  }else{
     manejoLuces(led[0],led[1],led[2],led[3],false);
  }
  checaBoton();
 //Se mandan los leds del semaforo 1 para que se haga el manejo correspondiente dependiendo la bandera del boton
    manejoLuces(led[4],led[5],led[6],led[7],botonSensor);

  checaBoton();
}
/* El siguiente metodo hace parpadear un led 4 
 * veces como indicacion de cambio por un tiempo definido en
 * la variable tiempoCambio donde la espera entre 
 * apagado seria de la mitad de dicha variable */
void cambio(int led){
  for(int i=0;i<3;i++){
    digitalWrite(led,LOW);
    delay(tiempoCambio/2);
    digitalWrite(led,HIGH);
    delay(tiempoCambio/2);
    digitalWrite(led,LOW);
  }
}
/* El siguiente metodo se encarga de recibir las luces de un semaforo y la señal de vuelta para asi
 * realizar el control a como es debido dependiendo las variables declaradas */
void manejoLuces(int verde,int vuelta, int amarillo,int rojo,boolean activador){
  //Enciende el led verde del semaforo en cuestion
  digitalWrite(verde,HIGH);
  //Si el rojo actual es igual a 11 estariamos tratando con el segundo semaforo entonces 
  //se adapta para que el rojo sea del contrario
  if(rojo==11){
    rojo-=4;
  }else{
    rojo+=4;
  }
  //Enciende el led rojo del semaforo contrario con el nuevo valor de rojo
  digitalWrite(rojo,HIGH);
  checaBoton();
  //Si el activador esta encendido entra a la vuelta
  if(activador){
      delay(tiempoPrevioVuelta);
      digitalWrite(vuelta,HIGH);
      delay(tiempoVuelta);
      cambio(vuelta);
  }
  //Es el tiempo que va a durar el verde despues de que se finaliza la
  //vuelta para posteriormente hacer la señal de cambio
  delay(tiempoVerde);
  cambio(verde);
  //Dado que en el cambio el led es apagado se inicia el amarillo y se 
  //hace una espera del tiempo predefinido en la variable tiempoAmarillo 
  digitalWrite(amarillo,HIGH);
  delay(tiempoAmarillo);
  //Se apagan el led amarillo y el rojo para dar la vuelta nuevamente
  digitalWrite(amarillo,LOW);
  digitalWrite(rojo,LOW);
}
/**Metodo para chechar el estado actual del boton**/
void checaBoton(){
  //Si esta con señal se hace verdadera la bandera que dice que el boton sensor esta activado
    if(digitalRead(2)==HIGH && botonSensor==false){
    botonSensor=true;
  } //Caso contrario se hace falsa y lo desactiva
  else if(digitalRead(2)==LOW && botonSensor==true){
    botonSensor=false;
  }

}
