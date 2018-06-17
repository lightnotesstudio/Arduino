/*
ANALISIS DE 4 SENSORES ULTRASONIDO MODELO HC SR04

ENVIO DE DATOS A TOUCHDESIGNER
 */
 
#define Pecho1 8
#define Ptrig1 9
#define Pecho2 6
#define Ptrig2 7
#define Pecho3 4
#define Ptrig3 5
#define Pecho4 2
#define Ptrig4 3

#define led1 13
#define led2 12
#define led3 11
#define led4 10

long duracionA, distanciaA;  
long duracionB, distanciaB;  
long duracionC, distanciaC;  
long duracionD, distanciaD;   
 
void setup() {                
  Serial.begin (115200);       // inicializa el puerto seria a 9600 baudios
  
  pinMode(Pecho1, INPUT);     // define el pin 8 como entrada (echo)
  pinMode(Ptrig1, OUTPUT);    // define el pin 9 como salida  (triger)
  pinMode(Pecho2, INPUT);     // define el pin 6 como entrada (echo)
  pinMode(Ptrig2,OUTPUT);    // define el pin 7 como salida  (triger)
  pinMode(Pecho3, INPUT);     // define el pin 4 como entrada (echo)
  pinMode(Ptrig3, OUTPUT);    // define el pin 5 como salida  (triger)
  pinMode(Pecho4, INPUT);     // define el pin 2 como entrada (echo)
  pinMode(Ptrig4, OUTPUT);    // define el pin 3 como salida  (triger)  
  
  pinMode(led1, 1);            // Define el pin 13 como salida
  pinMode(led2, 1);            // Define el pin 12 como salida
  pinMode(led3, 1);            // Define el pin 11 como salida
  pinMode(led4, 1);            // Define el pin 10 como salida
  }
  
void loop() {

// PRIMER SENSOR:
  
  digitalWrite(Ptrig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig1, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig1, LOW);
  
  duracionA = pulseIn(Pecho1, HIGH);
  distanciaA = (duracionA/2) / 29;            // calcula la distancia en centimetros
  
  if (distanciaA >= 500 || distanciaA <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
//    Serial.println("---");                  // no mide nada
  }
  else {
//    Serial.print(distanciaA);           // envia el valor de la distancia por el puerto serial
//    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(led1, 0);               // en bajo el pin 13
  }
  
   if (distanciaA <= 10 && distanciaA >= 1){
    digitalWrite(led1, 1);                     // en alto el pin 13 si la distancia es menor a 10cm
//    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }

// SEGUNDO SENSOR:

  digitalWrite(Ptrig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig2, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig2, LOW);
  
  duracionB = pulseIn(Pecho2, HIGH);
  distanciaB = (duracionB/2) / 29;            // calcula la distancia en centimetros
  
  if (distanciaB >= 500 || distanciaB <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
//    Serial.println("---");                  // no mide nada
  }
  else {
//    Serial.print(distanciaB);           // envia el valor de la distancia por el puerto serial
//    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(led2, 0);               // en bajo el pin 12
  }
  
   if (distanciaB <= 10 && distanciaB >= 1){
    digitalWrite(led2, 1);                     // en alto el pin 12 si la distancia es menor a 10cm
//    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }

// TERCERO SENSOR:

  digitalWrite(Ptrig3, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig3, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig3, LOW);
  
  duracionC = pulseIn(Pecho3, HIGH);
  distanciaC = (duracionC/2) / 29;            // calcula la distancia en centimetros
  
  if (distanciaC >= 500 || distanciaC <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
//    Serial.println("---");                  // no mide nada
  }
  else {
//    Serial.print(distanciaC);           // envia el valor de la distancia por el puerto serial
//    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(led3, 0);               // en bajo el pin 11
  }
  
   if (distanciaC <= 10 && distanciaC >= 1){
    digitalWrite(led3, 1);                     // en alto el pin 11 si la distancia es menor a 10cm
//    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  }

// CUARTO SENSOR:

  digitalWrite(Ptrig4, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig4, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig4, LOW);
  
  duracionD = pulseIn(Pecho4, HIGH);
  distanciaD = (duracionD/2) / 29;            // calcula la distancia en centimetros
  
  if (distanciaD >= 500 || distanciaD <= 0){  // si la distancia es mayor a 500cm o menor a 0cm 
//    Serial.println("---");                  // no mide nada
  }
  else {
//    Serial.print(distanciaD);           // envia el valor de la distancia por el puerto serial
//    Serial.println("cm");              // le coloca a la distancia los centimetros "cm"
    digitalWrite(led4, 0);               // en bajo el pin 10
  }
  
   if (distanciaD <= 10 && distanciaD >= 1){
    digitalWrite(led4, 1);                     // en alto el pin 10 si la distancia es menor a 10cm
//    Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
  } 
  
// ENVIAR DATOS DE SENSORES A TOUCHDESIGNER:

    Serial.print("sensor1=");
    Serial.print(distanciaA);
    Serial.print(" sensor2=");
    Serial.print(distanciaB);
    Serial.print(" sensor3=");
    Serial.print(distanciaC);
    Serial.print(" sensor4=");
    Serial.print(distanciaD);

    Serial.println( );

  delay(100);                                // espera 1000ms para que se logre ver la distancia en la consola
}
