#include  <SPI.h> //kütüphaneler koda eklenir.
#include "nRF24L01.h"
#include "RF24.h"
int mesaj[1]; //mesaj isminde bir dizi atanır. Bu yollanacak verinin dizinin elemanı şeklinde yollanmasına olana sağlayacaktır.
RF24 verici(9,10); //CE ve CSN pinleri tanımlanır. 
const uint64_t veriadresi = 0xE8E8F0F0E1LL; //veri alışverişi yapılacak adres yolu atanır. verici ve alıcı kodda bu aynı olmalıdır. 
int butonpin1 = 7; //4 adet buton için pin atamaları yapılır. 
int butonpin2= 6;
int butonpin3= 5;
int butonpin4= 4;

void setup(){
Serial.begin(9600); //seri veri iletişim başlatılır. 
pinMode(butonpin1, INPUT_PULLUP); //butonlar için pinler çıkış olarak tanımlanır. 
pinMode(butonpin2, INPUT_PULLUP);
pinMode(butonpin3, INPUT_PULLUP);
pinMode(butonpin4, INPUT_PULLUP);
verici.begin(); //NRF24L01 başlatılır. 
verici.openWritingPipe(veriadresi); //verileri yazmak için veriadresi yolu açılır. 
}
 
void loop()
{ //Eğer butonlara basılmazsa alıcıya 0 yollanır. 
if ((digitalRead(butonpin1) == LOW) || (digitalRead(butonpin2) == LOW)|| (digitalRead(butonpin3) == LOW)|| (digitalRead(butonpin4) == LOW)){
mesaj[0] = 0;}
if (digitalRead(butonpin1) == HIGH){
mesaj[0] = 1;} //eğer 1.butona basılırsa 1 yollanır. 
if (digitalRead(butonpin2) == HIGH){
mesaj[0] = 2;} //eğer 2.butona basılırsa 2 yollanır. 
if (digitalRead(butonpin3) == HIGH){
mesaj[0] = 3;} //eğer 3.butona basılırsa 3 yollanır. 
if (digitalRead(butonpin4) == HIGH){
mesaj[0] = 4;}  //eğer 4.butona basılırsa 4 yollanır. 

verici.write(mesaj, 1); //veri yollanır. 
}

