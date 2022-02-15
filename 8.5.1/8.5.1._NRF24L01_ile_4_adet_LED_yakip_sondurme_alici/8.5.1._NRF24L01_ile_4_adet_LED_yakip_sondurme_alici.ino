#include <SPI.h> //kütüphaneler koda eklenir. 
#include "nRF24L01.h"
#include "RF24.h"
boolean degisken; //degisken adlı bir değişken tanımlanır. 
int mesaj[1]; //mesaj isminde bir dizi tanımlanır. 
RF24 verici(9,10); //CE ve CSN pinleri tanımlanır. 
const uint64_t veriadresi = 0xE8E8F0F0E1LL; //veri alışverişi yapılacak adres yolu atanır.
int kirmiziLEDpin =7; //LEDler için pin atamaları yapılır. 
int yesilLEDpin =6;
int sariLEDpin =5;
int beyazLEDpin =4;

void setup()
{
Serial.begin(9600); //seri veri iletişimi başlatılır. 
verici.begin(); //NRF24L01 başlatılır. 
verici.openReadingPipe(1,veriadresi); //veri okuma için veriadresi yolu açılır. 
verici.startListening();  //Açılan veri yolundan veri dinleme işlemi başlatılır. 
pinMode(kirmiziLEDpin, OUTPUT); //LED pinleri çıkış olarak tanımlanır. 
pinMode(yesilLEDpin, OUTPUT);
pinMode(sariLEDpin, OUTPUT);
pinMode(beyazLEDpin, OUTPUT);
}

void loop(){
if (verici.available()){ //okunacak veri olup olmadığı kontrol edilir. 
degisken=false; //degisken ilk değer false atanır. 
while(!degisken){  //eğer veri girişi yapılırsa değişken true değeri alır ve program devam eder. 
degisken=verici.read(mesaj, 1); //vericiden okunan değer degiskene atanır. 
}
Serial.println(mesaj[0]); //okunan veri seri port ekrana yazdırılır. 
if (mesaj[0] == 1){ //gelen veri 1 ise kırmızı LED yanar. 
digitalWrite(kirmiziLEDpin, HIGH);}
if (mesaj[0] == 2){  //gelen veri 2 ise yesil LED yanar. 
digitalWrite(yesilLEDpin, HIGH);}
if (mesaj[0] == 3){  //gelen veri 3 ise sarı LED yanar. 
digitalWrite(sariLEDpin, HIGH);}
if (mesaj[0] == 4){  //gelen veri 4 ise beyaz LED yanar. 
digitalWrite(beyazLEDpin, HIGH);}

if(mesaj[0] == 0){  //gelen veri 0 ise LEDler sönük durumdadır. 
digitalWrite(kirmiziLEDpin, LOW);
digitalWrite(yesilLEDpin, LOW);
digitalWrite(sariLEDpin, LOW);
digitalWrite(beyazLEDpin, LOW);
}
}
}
