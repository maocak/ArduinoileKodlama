// Kodun çalışması için gerekli olan kütüphaneler eklenir.
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
 
#define DHTPIN 3 //DHT11 in bağlanacağı pin numarası tanımlanır. 
#define DHTTYPE DHT11   //kullanılacak sensör türü DHT11 olarak atanır. Kütüphane aynı zamanda DHT22 içinde çalıştığı için bunu belirtmemiz gerekir.
DHT dht(DHTPIN, DHTTYPE,20); //pin çıkışı ve türü tanımlanan DHT sensör için nesne oluşturulur
 
const int CSpin = 10;  //CS pin olarak 10  nolu dijital pin atanır.
File dosya;  //dosya isminde SD kart nesnesi oluşturulur. Tüm SD kart fonksiyonların başında bu nesne ismi getirilir. 
 
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

dht.begin();//DHT11 sensörü başlatılır.
 
}
 
void loop()
{
delay(2000);
dosya = SD.open("DHT11.CSV", FILE_WRITE); // dht11.csv isminde bir dosya açılır. open komutunun özelliğinden dolayı dosya ismi mevcut olmasa da oluşturulmaktadır.
// Sıcaklık veya nemi okumak yaklaşık 250 milisaniye alır!
// Sensör okumaları 2 saniyeye kadar eski olabilir 
float nem = dht.readHumidity();
float sicaklik = dht.readTemperature();

if (dosya)  // dosya açıldığında, yazma işlemi başlar
{
Serial.print("DHT11.CSV dosyası açıldı");
dosya.print(sicaklik);
dosya.print(",");
dosya.println(nem);

// dosya kapanır:
dosya.close();
Serial.println("\nDHT11.CSV dosyası kapandı.");

Serial.print("Sıcaklık ve nem değerleri: "); //Ekrana Sıcaklık ve nem değerleri yazılır. 
Serial.print((float)sicaklik); //okunan sıcaklık değeri ekrana yazdırılır. 
Serial.print("C, ");
Serial.print((float)nem); //okunan nem değeri ekrana yazdırılır. 
Serial.println("%");

} 
else 
{
// eğer dosya açılamaz ve yazma işlemi yapılamazsa, hata verir:
Serial.println("DHT11.CSV dosyası açılamadı. Yazma işleminde hata");
}
}
