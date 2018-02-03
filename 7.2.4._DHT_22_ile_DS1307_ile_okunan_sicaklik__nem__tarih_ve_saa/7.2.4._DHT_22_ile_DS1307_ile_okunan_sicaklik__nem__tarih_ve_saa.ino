// Kodun çalışması için gerekli olan kütüphaneler eklenir.
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h> //LCD kütüphanesini ekler. 


RTC_DS1307 rtc; //RTC nesnesi oluşturulur. 

char daysOfTheWeek[7][12] = {"Pazar", "Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma", "Cumartesi"}; //7 gün 12 ay üzerinden 2 boyutlu bir dizi oluşturulur. 
 
#define DHTPIN 8 //DHT11 in bağlanacağı pin numarası tanımlanır. 
#define DHTTYPE DHT22   //kullanılacak sensör türü DHT22 olarak atanır. Kütüphane aynı //zamanda DHT11 içinde çalıştığı için bunu belirtmemiz gerekir.
DHT dht(DHTPIN, DHTTYPE,20); //pin çıkışı ve türü tanımlanan DHT sensör için nesne //oluşturulur

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);   
  
const int CSpin = 10;  //CS pin olarak 10  nolu dijital pin atanır.
File dosya;  //dosya isminde SD kart nesnesi oluşturulur. Tüm SD kart fonksiyonların başında //bu nesne ismi getirilir. 

void setup()
{
// Seri veri iletişimi başlatılır ve seri port ekranın açılması beklenir:
Serial.begin(9600);

while (!Serial) {
; // Seri portun bağlanması beklenir. USB portun bilgisayara takılı olması gerekir.
}
 
Serial.print("SD kart başlatılıyor...");

if (!SD.begin(CSpin)) //Eğer kart başlatılamazsa uyarı verir.
{
Serial.println("SD kart başlatılamadı.!");
return;
}
Serial.println("SD kart hazır."); //kart başlatmada sıkıntı çıkmazsa bu uyarı yazdırılır.

dht.begin();  //DHT22 sensörü başlatılır.

 if (! rtc.begin()) { // Eğer modül başlatılamazsa...
Serial.println("RTC modül bulunamadı");  //ekrana bu uyarı yazar. 
while (1); //programdan çıkılır. 
}

if (! rtc.isrunning()) {  //Eğer modül başlatılıp ancak çalışmazsa...
Serial.println("RTC modül çalışmıyor!");  // ekrana bu uyarı yazar. 

// Eğer, RTC ilk defa kullanılıyorsa ya da pili değiştirildiyse bu kodun aktif hale getirilerek //derleme anındaki bilgisayar saatinin RTC ye yazılması sağlanır. 
rtc.adjust(DateTime((__DATE__), (__TIME__)));

}

// LCD'inin sütun ve satır sayısı belirtilerek başlatılır. 
lcd.begin(16, 2); 

} 


void loop()
{

DateTime now = rtc.now(); //DateTime nesnesi RTC ye yazılan gün, ay,yıl haftanın günü, //saat, dakika ve saniye bilgilerini alır. 

// Sıcaklık veya nemi okumak yaklaşık 250 milisaniye alır!
// Sensör okumaları 2 saniyeye kadar eski olabilir 
float nem = dht.readHumidity();
float sicaklik = dht.readTemperature();


dosya = SD.open("veri.txt", FILE_WRITE); // veri.txt isminde bir dosya açılır. open //komutunun özelliğinden dolayı dosya ismi mevcut olmasa da oluşturulmaktadır.

if (dosya)  // dosya açıldığında, yazma işlemi başlar
{
Serial.print("veri.txt dosyası açıldı");
dosya.print(sicaklik); //SD karta sıcaklık yazılır. 
dosya.print(", ");
dosya.print(nem); //SD karta nem değeri yazılır. 
dosya.print(", ");
dosya.print(now.day(), DEC);  //SD karta gün yazılır. 
dosya.print('/');
dosya.print(now.month(), DEC); //SD karta ay yazılır. 
dosya.print('/');
dosya.print(now.year(), DEC);  //SD karta yıl yazılır. 
dosya.print(" (");
dosya.print(daysOfTheWeek[now.dayOfTheWeek()]);  //SD karta haftanın günü //parantez içinde yazdırılır.
dosya.print(") ");
dosya.print(now.hour(), DEC); //SD karta saat yazılır. 
dosya.print(':');
if (now.minute() < 10)  //10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan küçük //dakikaların başına 0 eklenir ve 2 basamaklı yapılır. 
{
dosya.print("0");
}
dosya.print(now.minute(), DEC); //SD karta dakika yazılır. 
dosya.print(':');
if (now.second() < 10)  //10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan küçük //saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
dosya.print("0");
}
dosya.println(now.second(), DEC);
// dosya kapanır:
dosya.close();
Serial.println("\nveri.txt dosyası kapandı.");
Serial.println("");
Serial.print("Ölçüm değerleri, tarih ve zaman: "); //Ekrana Sıcaklık ve nem değerleri yazılır. 
Serial.print((float)sicaklik); //okunan sıcaklık değeri ekrana yazdırılır. 
Serial.print("C, ");
Serial.print((float)nem); //okunan nem değeri ekrana yazdırılır. 
Serial.print("%, ");
Serial.print(now.day(), DEC); //Seri port ekranına gün yazdırılır. 
Serial.print('/');
Serial.print(now.month(), DEC); //Seri port ekranına ay yazdırılır.
Serial.print('/');
Serial.print(now.year(), DEC);  //Seri port ekranına yıl yazdırılır.
Serial.print(" (");
Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);  //Seri port ekranına haftanın günü //parantez içinde yazdırılır.
Serial.print(") ");
Serial.print(now.hour(), DEC); //Seri port ekranına saat yazdırılır.
Serial.print(':');
if (now.minute() < 10)  //10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan küçük //dakikaların başına 0 eklenir ve 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.print(now.minute(), DEC); //Seri port ekranına dakika yazdırılır.
Serial.print(':');
if (now.second() < 10)  //10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan küçük //saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.println(now.second(), DEC); //Seri port ekranına saniye yazdırılır.
Serial.println("");   
} 
else 
{
// eğer dosya açılamaz ve yazma işlemi yapılamazsa, hata verir:
Serial.println("veri.txt dosyası açılamadı. Yazma işleminde hata");
}
// imleç (0,0)/1. satırdan başlatılır. 
lcd.setCursor(0,0); 
//Sıcaklık değeri mesajı ekrana yazdırılır. 
lcd.print("Sicaklik:"); 
lcd.print(sicaklik); 
lcd.print(" C");
lcd.setCursor(0,1); 
//Nem mesajı ekrana yazdırılır. 
lcd.print("Nem: "); 
// ölçülen nem değeri 2.satırda yazar. 
lcd.print(nem); 
delay(2000);
}

