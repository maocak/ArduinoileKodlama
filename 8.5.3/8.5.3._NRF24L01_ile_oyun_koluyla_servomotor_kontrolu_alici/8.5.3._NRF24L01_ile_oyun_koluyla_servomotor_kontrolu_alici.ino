#include <SPI.h> //kütüphaneler koda eklenir. 
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
    
RF24 verici(9, 10); // CE, CSN pinleri tanımlanır. 
const uint64_t veriadresi = 0xE8E8F0F0E1LL; //veri alışverişi yapılacak adres yolu atanır.
Servo servomotor;  //servomotor için nesne oluşturulur. 
float deger[1]; //deger isminde bir dizi tanımlanır. 

void setup(void) {
Serial.begin(9600);  //seri port iletişimi başlatılır. 
servomotor.attach(5);  //servomotor 5 nolu dijital pine bağlanır. 
verici.begin();  //NRF24L01 başlatılır. 
verici.openReadingPipe(1, veriadresi);  //veri okuma için veriadresi yolu açılır
verici.startListening();  //Açılan veri yolundan veri dinleme işlemi başlatılır.
}

void loop(void) {
if (verici.available()) {  //okunacak veri olup olmadığı kontrol edilir.
bool degisken = false; //degisken ilk değer false atanır.
while (!degisken) //eğer veri girişi yapılırsa değişken true değeri alır ve program devam eder. 
{
degisken = verici.read(deger, sizeof(deger)); //vericiden okunan değer degiskene atanır.
Serial.println(deger[0]); //okunan veri seri port ekrana yazdırılır.
servomotor.write(deger[0]); //servomotor vericiden gelen açıya uygun olarak yönlendirilir. 
}
}
}
