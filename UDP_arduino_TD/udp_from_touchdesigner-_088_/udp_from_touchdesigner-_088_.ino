#include <EtherCard.h>
#include <IPAddress.h>

#define STATIC 1  // configurar en 1 para desactivar DHCP (ajustar myip/gwip valores)

#if STATIC
// ethernet arduino ip address
static byte myip[] = { 192,168,1,40 };
// gateway ip address
static byte gwip[] = { 192,168,1,1 };
#endif

// ethernet mac address - unica en tu red
static byte mymac[] = { 0x70,0x69,0x69,0x2D,0x30,0x31 };

int VL1 = 0;
int VL2 = 0;
int VL3 = 0;
int VL4 = 0;


int ledPin1 =  3;      // LED pin numero
int ledPin2 =  5;      // LED pin numero 
int ledPin3 =  6;      // LED pin numero 
int ledPin4 =  9;      // LED pin numero 


byte Ethernet::buffer[500]; // tcp/ip envio y recepcion buffer

//Llamada para imprimir por serial los paquetes recibidos

void udpSerialPrint(uint16_t dest_port, uint8_t src_ip[4], uint16_t src_port, const char *data, uint16_t len){
  IPAddress src(src_ip[0],src_ip[1],src_ip[2],src_ip[3]);
    
  int valor1;
  valor1 = atoi(&data[1]);

  int valor2;
  valor2 = atoi(&data[6]);

  int valor3;
  valor3 = atoi(&data[11]);
  
  int valor4;
  valor4 = atoi(&data[16]);

    
  VL1 = valor1;
  VL2 = valor2;
  VL3 = valor3;
  VL4 = valor4;


    Serial.print("valor1: ");
    Serial.print(valor1);
    Serial.print(" || ");
    Serial.print("valor2: ");
    Serial.print(valor2);
    Serial.print(" || ");
    Serial.print("valor3: ");
    Serial.print(valor3);
    Serial.print(" || ");
    Serial.print("valor4: ");
    Serial.println(valor4);

}

void setup(){
  Serial.begin(57600);

   // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);  
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  Serial.println(F("\n"));

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println(F("Failed to access Ethernet controller"));
#if STATIC
  ether.staticSetup(myip, gwip);
#else
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));
#endif

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);
  ether.printIp("DNS: ", ether.dnsip);

  //register udpSerialPrint() to port 1337
  ether.udpServerListenOnPort(&udpSerialPrint, 1337);

  //register udpSerialPrint() to port 42.
  ether.udpServerListenOnPort(&udpSerialPrint, 42);
}

void loop(){
  //this must be called for ethercard functions to work.
  ether.packetLoop(ether.packetReceive());

  analogWrite(ledPin1, VL1);  // animar led 1
  analogWrite(ledPin2, VL2);  // animar led 2
  analogWrite(ledPin3, VL3);  // animar led 3
  analogWrite(ledPin4, VL4);  // animar led 4

}

