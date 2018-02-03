#include <SPI.h>   //kütüphaneler koda eklenir.
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //I2C LCD pin uçları tanımlanır.
// (I2C Adres, Enable_pin, Rw_pin, Rs_pin, d4, d5, d6, d7, arkaışık_pin, polarite)

float deger[2]; //2 elemanlı değer isimli bir dizi tanımlanır. 

RF24 verici(9, 10); //CE ve CSN pinleri tanımlanır.
const uint64_t veriadresi = 0xE8E8F0F0E1LL; //veri alışverişi yapılacak adres yolu atanır.

void setup(void) {
Serial.begin(9600); //seri veri iletişimi başlatılır.
verici.begin();  //NRF24L01 başlatılır. 
verici.openReadingPipe(1, veriadresi);  //veri okuma için veriadresi yolu açılır
verici.startListening();  //Açılan veri yolundan veri dinleme işlemi başlatılır. 
lcd.begin(16, 2); //LCDin sütun ve satır sayıları tanımlanarak başlatılır.
lcd.backlight(); //LCD arka plan ışığı başlatılır. 
lcd.clear();  //LCD ekran temizlenir. 
lcd.print("Sicaklik & Nem");  //Ekrana yazı yazdırılır. 
delay(1000); //1 sn beklenir. 
lcd.clear(); //LCD ekran temizlenir. 
lcd.print("Basliyor....."); //Ekrana yazı yazdırılır. 
delay(1000); //1 sn beklenir. 
lcd.clear(); //LCD ekran yazdırılır. 
}

void loop(void)
{
if ( verici.available() ) //okunacak veri olup olmadığı kontrol edilir. 
{
bool degisken = false; //degisken ilk değer false atanır.
while (!degisken) //eğer veri girişi yapılırsa değişken true değeri alır ve program devam eder. 
{
degisken = verici.read(deger, sizeof(deger)); //vericiden okunan değer degiskene atanır. 
delay(500); //Yarım saniye beklenir. 
Serial.println(deger[0]); //okunan veri seri port ekrana yazdırılır. 
Serial.println(deger[1]); //okunan veri seri port ekrana yazdırılır.
lcd.setCursor(0, 0); //İmleç ekranın sol üst köşesine getirilir. 
lcd.print("Sicaklik:"); //Ekrana Sıcaklık yazdırılır. 
lcd.setCursor(0, 1); //İmleç 2. satıra getirilir. 
lcd.print("Nem     :"); //Ekrana yazdırılır. 
lcd.setCursor(9, 0); //İmleç 9.sütun 1. satıra getirilir...
lcd.print(deger[0]); //vericiden okunan sıcaklık değeri yazdırılır.
lcd.print(" C");  //C yazdırılır. 
lcd.setCursor(9, 1);  //İmleç 9.sütun 2.satıra getirilir.
lcd.print(deger[1]);  //vericiden okunan nem değeri yazdırılır. 
lcd.print(" %");  //% yazdırılır. 
delay(1000); //1 saniye beklenir. 
}
}
else
{
lcd.setCursor(0, 0); //eğer vericiden değer alınamazsa imleç sol üst köşeye gider
lcd.print("Veri alinamiyor!"); //Veri alınamıyor yazar...
}
}
