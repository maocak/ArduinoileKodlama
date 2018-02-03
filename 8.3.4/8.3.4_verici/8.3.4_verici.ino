//Kütüphaneler eklenir. 
#include <VirtualWire.h>
#include <DHT.h>
int ledPin = 10; //LED pin tanımlanır. 
#define dhtPin 4 //DHT11 sensör pini tanımlanır. 
#define dhtType DHT11 //sensör türü DHT1 olarak tanımlanır. 

DHT dht(dhtPin, dhtType); //DHT sensörü başlatılır. 

char veri0[3]; //değişkenler tanımlanır. 
char veri1[3];

int sicaklik = 0; //değişkenlere ilk değerleri atanır. 
int nem = 0;

void setup() {
Serial.begin(9600);
dht.begin();  // initialing the DHT sensor
pinMode(ledPin,OUTPUT);
vw_setup(4800); // Kütüphane iletişim hızı belirlenir.
vw_set_tx_pin(12);  // veri yollama için kullanılacak pin tanımlanır. 
}

void loop() {
digitalWrite(ledPin, HIGH); 
sicaklik = dht.readTemperature(); // sıcaklık değerlerini okuyacak değişkene atama yapılır. 
nem = dht.readHumidity();   // nem değerlerini okuyacak değişkene atama yapılır. 
itoa(sicaklik, veri0, 10); // Okunan sıcaklık değerleri veri isminde bir diziye atanır.   
itoa(nem, veri1, 10);  // Okunan nem değerleri veri isminde bir diziye atanır.
strcat(veri0, veri1);  // veri0 ve veri1 dizileri birleştirilerek bir dizi yapılır. Bunun nedeni, tek yönlü bir iletişim olmasından kaynaklanmaktadır.
vw_send((uint8_t *)veri0, strlen(veri0)); // birleştirilen veri dizisi alıcıya yollanır. 
vw_wait_tx();  // Yollama işleminin tamamlanması beklenir. 
digitalWrite(ledPin, LOW); 
delay(2000); //2 saniyede bir okuma yapılır ve veri yollanır.
Serial.println(veri0); //Okunan verilen aynı zamanda yanyana seri port ekranından da takip edilebilir. 
}
