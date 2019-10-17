int led[]={5,6,7,8,9,10,11,4}; 
/* 
 *  NOMENCLATURA DE INDICES SEMAFORO 1 Y 2
 * led[7]=4 --> Semaforo 1 vuelta
 * led[0]=5 --> Semaforo 1 verde
 * led[1]=6 --> Semaforo 1 amarillo
 * led[2]=7 --> Semaforo 1 rojo
 * led[3]=8 --> Semaforo 2 verde
 * led[4]=9 --> Semaforo 2 amarillo
 * led[5]=10 --> Semaforo 2 rojo
 * led[6]=11 --> Semaforo 2 vuelta
 * 
*/
void setup() {
  // put your setup code here, to run once:
  //Se recorren todo el arreglo de leds para inicializar
  for(int i=0;i<8;i++){
    pinMode(led[i],OUTPUT);

  }
}
void loop() {
  // put your main code here, to run repeatedly:
  //Apaga todos los leds
  for(int i=0;i<7;i++){
    digitalWrite(led[i],LOW);
  }
  //Enciende el led verde del semaforo 1
  digitalWrite(led[0],HIGH);
    //Enciende el led rojo del semaforo 2
  digitalWrite(led[5],HIGH);
  //Enciende la vuelta verde del semaforo numero 1 se espera 2 segundos y hace un cambio de luz antes de apagarse
  digitalWrite(led[7],HIGH);
  delay(2000);
  cambio(led[7]);
  //Se espera 5 segundos antes del cambio de luz
  delay(5000);
  //Parpadea el led verde del semaforo 1 
  cambio(led[0]);
  //En el cambio el led verde del semaforo 1 es apagado y aqui se enciende el led amarillo del semaforo 1
  digitalWrite(led[1],HIGH);
  //Se espera 3 segundos manteniendo el amarillo
  delay(3000);
  //Apaga el led amarillo del semaforo 1
  digitalWrite(led[1],LOW);
  //Enciende el led rojo del semaforo 1
  digitalWrite(led[2],HIGH);
  //Apaga el led rojo del semaforo 2
  digitalWrite(led[5],LOW);
  //Enciende el led verde del semaforo 2
  digitalWrite(led[3],HIGH);

  //Enciende el led vuelta del semaforo 2 y se espera 2 segundos antes de hacer el cambio y apagarse
  digitalWrite(led[6],HIGH);
  delay(2000);
  cambio(led[6]);
  //Se hace una espera de 5 segundos antes del cambio de luz
  delay(5000);
  //Se hace parpadear el led verde del semaforo 2 para indicar el cambio 
  cambio(led[3]);
  //Se enciende el led amarillo del semaforo 2
  digitalWrite(led[4],HIGH);
  //Se hace una espera de 2 segundos y se reinicia
  delay(2000);
}
//Es un metodo para hacer parpadear un led cada medio segundo, en este caso recibe la id de un led y al final lo deja apagado
void cambio(int led){
  for(int i=0;i<3;i++){
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
  }
  
}
