#include <SPI.h>  //kütüphaneler koda eklenir. 
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>

#define DHTPIN 3 //DHT11 in bağlanacağı pin numarası tanımlanır. 
#define DHTTYPE DHT11//kullanılacak sensör türü DHT11 olarak atanır. Kütüphane aynı zamanda DHT22 içinde çalıştığı için bunu belirtmemiz gerekir.
//Eğer DHT22 kullanılırsa kod #define DHTTYPE DHT22 şeklinde olmalıdır. 
DHT dht(DHTPIN,DHTTYPE, 20);//pin çıkışı ve türü tanımlanan DHT sensörü başlatılır. 

float deger[2]; //2 elemanlı deger isminde bir dizi tanımlanır. 

RF24 verici(9, 10);  //CE ve CSN pinleri tanımlanır. 
const uint64_t veriadresi = 0xE8E8F0F0E1LL;  //veri alışverişi yapılacak adres yolu atanır. verici ve alıcı kodda bu aynı olmalıdır.

void setup(void) {
Serial.begin(9600); //seri veri iletişimi başlatılır. 
verici.begin();  //NRF24L01 başlatılır. 
verici.openWritingPipe(veriadresi); //verileri yazmak için veriadresi yolu açılır.
}

void loop(void)
{
float nem = dht.readHumidity();//sensörden okunan nem değeri nem isimli değişkene atanır. 
float sicaklik = dht.readTemperature();//sensörden okunan sıcaklık değeri sicaklik isimli değişkene atanır. 

deger[0] = sicaklik; //dizinin 1.elemanına sıcaklık değeri atanır. 
deger[1] = nem;  //dizinin 2.elemanına nem değeri atanır. 
Serial.println(deger[0]); //okunan veri seri port ekrana yazdırılır. 
Serial.println(deger[1]);
verici.write(deger, sizeof(deger)); //dizinin elemanları olarak veri yollanır. 

}
