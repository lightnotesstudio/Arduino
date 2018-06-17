// 16 TOUCH SENSOR SHIELD PARA ARDUINO MEGA

#include <CapacitiveSensor.h>

// definimos los 16 sensores: Usaremos los pin del 22-53 para 
// las 32 entradas necesarias

CapacitiveSensor capSensor1 = CapacitiveSensor (23,22);
CapacitiveSensor capSensor2 = CapacitiveSensor (25,24);
CapacitiveSensor capSensor3 = CapacitiveSensor (27,26);
CapacitiveSensor capSensor4 = CapacitiveSensor (29,28);
CapacitiveSensor capSensor5 = CapacitiveSensor (31,30);
CapacitiveSensor capSensor6 = CapacitiveSensor (33,32);
CapacitiveSensor capSensor7 = CapacitiveSensor (35,34);
CapacitiveSensor capSensor8 = CapacitiveSensor (37,36);
CapacitiveSensor capSensor9 = CapacitiveSensor (39,38);
CapacitiveSensor capSensor10 = CapacitiveSensor (41,40);
CapacitiveSensor capSensor11 = CapacitiveSensor (43,42);
CapacitiveSensor capSensor12 = CapacitiveSensor (45,44);
CapacitiveSensor capSensor13 = CapacitiveSensor (47,46);
CapacitiveSensor capSensor14 = CapacitiveSensor (49,48);
CapacitiveSensor capSensor15 = CapacitiveSensor (51,50);
CapacitiveSensor capSensor16 = CapacitiveSensor (53,52);

void setup()					
{
	Serial.begin(115200);
}

void loop(){

 // LECTURA DE SENSOR 1:
        long sensorValue1 =  capSensor1.capacitiveSensor(22);
         Serial.print("sensor1=");
         Serial.print(sensorValue1);
 // LECTURA DE SENSOR 2:
        long sensorValue2 =  capSensor2.capacitiveSensor(24);
         Serial.print(" sensor2=");
         Serial.print(sensorValue2);
 // LECTURA DE SENSOR 3:
        long sensorValue3 =  capSensor3.capacitiveSensor(26);
         Serial.print(" sensor3=");
         Serial.print(sensorValue3);
 // LECTURA DE SENSOR 4:
        long sensorValue4 =  capSensor4.capacitiveSensor(28);
         Serial.print(" sensor4=");
         Serial.print(sensorValue4);
 // LECTURA DE SENSOR 5:
        long sensorValue5 =  capSensor5.capacitiveSensor(30);
         Serial.print(" sensor5=");
         Serial.print(sensorValue5);
 // LECTURA DE SENSOR 6:
        long sensorValue6 =  capSensor6.capacitiveSensor(32);
         Serial.print(" sensor6=");
         Serial.print(sensorValue6);
 // LECTURA DE SENSOR 7:
        long sensorValue7 =  capSensor7.capacitiveSensor(34);
         Serial.print(" sensor7=");
         Serial.print(sensorValue7);
 // LECTURA DE SENSOR 8:
        long sensorValue8 =  capSensor8.capacitiveSensor(36);
         Serial.print(" sensor8=");
         Serial.print(sensorValue8);
 // LECTURA DE SENSOR 9:
        long sensorValue9 =  capSensor9.capacitiveSensor(38);
         Serial.print(" sensor9=");
         Serial.print(sensorValue9);
 // LECTURA DE SENSOR 10:
        long sensorValue10 =  capSensor10.capacitiveSensor(40);
         Serial.print(" sensor10=");
         Serial.print(sensorValue10);
 // LECTURA DE SENSOR 11:
        long sensorValue11 =  capSensor11.capacitiveSensor(42);
         Serial.print(" sensor11=");
         Serial.print(sensorValue11);
 // LECTURA DE SENSOR 12:
        long sensorValue12 =  capSensor12.capacitiveSensor(44);
         Serial.print(" sensor12=");
         Serial.print(sensorValue12);
 // LECTURA DE SENSOR 13:
        long sensorValue13 =  capSensor13.capacitiveSensor(46);
         Serial.print(" sensor13=");
         Serial.print(sensorValue13);
 // LECTURA DE SENSOR 14:
        long sensorValue14 =  capSensor14.capacitiveSensor(48);
         Serial.print(" sensor14=");
         Serial.print(sensorValue14);
 // LECTURA DE SENSOR 15:
        long sensorValue15 =  capSensor15.capacitiveSensor(50);
         Serial.print(" sensor15=");
         Serial.print(sensorValue15);
 // LECTURA DE SENSOR 16:
        long sensorValue16 =  capSensor16.capacitiveSensor(52);
         Serial.print(" sensor16=");
         Serial.print(sensorValue16);

Serial.println( );
      delay(30);
   }

