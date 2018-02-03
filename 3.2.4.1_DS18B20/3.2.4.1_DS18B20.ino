// Kütüphaneler eklenir.
#include <OneWire.h> 
#include <DallasTemperature.h>
// Veri kablosu, Arduino UNO'nun 7 nolu dijital pinine bağlanır. 
#define sensorpin 7 
// DS18B20 aygıtı başlatılır.
OneWire oneWire(sensorpin); 
// DS18B20 aygıtı başlatıldıktan sonra matematiksel hesaplamaları yapacak olan ikinci kütüphaneye(DallasTemperature)devredilir.
DallasTemperature sensors(&oneWire);
float  sicaklik; //sicaklik isminde bir değişken tanımlanır. 

void setup(void) 
{ 
// seri veri girişi başlatılır.
Serial.begin(9600); 
// kütüphaneler başlatılır.  
sensors.begin(); 
} 

void loop(void) 
{ 
Serial.print("Sıcaklık değeri okunuyor..."); 
sensors.requestTemperatures(); // sıcaklık değerlerini ölçmek için sensöre komut gönderilir. 
Serial.println("OK"); 
sicaklik=sensors.getTempCByIndex(0); //sensörden okunan değer sicaklik ismindeki değişkene atanır. 
//Burda byindex kullanılmasının nedeni kütüphane tarafından kontrol edilen birden fazla onewire aygıtı olabilir.
//0, DS18B20 aygıtının ilk sırada okunmasını sağlar. 
Serial.print("Sıcaklık: "); 
Serial.println(sicaklik);  
delay(1000); //Her 1sn'de sıcaklık okunur. 
} 
