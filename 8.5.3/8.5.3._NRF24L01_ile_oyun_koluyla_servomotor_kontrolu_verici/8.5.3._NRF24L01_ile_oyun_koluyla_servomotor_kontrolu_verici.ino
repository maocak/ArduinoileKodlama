#include <SPI.h> //kütüphaneler koda eklenir.
#include <nRF24L01.h>
#include <RF24.h>

RF24 verici(9, 10); // CE, CSN pinleri tanımlanır. 
const uint64_t veriadresi = 0xE8E8F0F0E1LL; //veri alışverişi yapılacak adres yolu atanır. verici ve alıcı kodda bu aynı olmalıdır. 
float deger[1]; //deger isminde bir dizi tanımlanır. 

void setup(void) {
Serial.begin(9600);  //seri veri iletişimi başlatılır. 
verici.begin();  //NRF24L01 başlatılır. 
verici.openWritingPipe(veriadresi); //verileri yazmak için veriadresi yolu açılır. 
verici.startListening();  //veri okuma için veriadresi yolu dinlenir. 
}

void loop(void) {
  
int analogdeger = analogRead(A0); //A0 analog değer okunarak değişkene atanır. 
int acidegeri = map(analogdeger, 0, 1023, 0, 180); //okunan analog değer, 0-180 arası dereceye dönüştürülür. 
deger[0]= acidegeri; //derece, deger dizinine atanır. 
Serial.println(deger[0]);  //okunan değer, seri port ekrana yazdırılır.
verici.write(deger, sizeof(deger));  //okunan derece alıcıya gönderilir. 

}
