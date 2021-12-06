#include <DHT.h>
#define DHTPIN 3 //DHT11 in bağlanacağı pin numarası tanımlanır. 
#define DHTTYPE DHT11//kullanılacak sensör türü DHT11 olarak atanır. Kütüphane aynı zamanda DHT22 içinde çalıştığı için bunu belirtmemiz gerekir.
//Eğer DHT22 kullanılırsa kod #define DHTTYPE DHT22 şeklinde olmalıdır. 
DHT dht(DHTPIN,DHTTYPE, 20);//pin çıkışı ve türü tanımlanan DHT sensörü başlatılır. 
const int ledPin=10;//led pini tanımlanır. 
const int buzzerPin=5; //buzzer pini tanımlanır. 

void setup() 
{
Serial.begin(9600); //seri veri iletişimi başlatılır. 
pinMode (ledPin, OUTPUT); //ledpini çıkış olarak tanımlanır. 
pinMode (buzzerPin, OUTPUT); //buzzer pini çıkış olarak tanımlanır. 
dht.begin();
}

void loop() {
float nem = dht.readHumidity();//sensörden okunan nem değeri nem isimli değişkene atanır. 
float sicaklik = dht.readTemperature();//sensörden okunan sıcaklık değeri sicaklik isimli değişkene atanır. 
Serial.print("Sıcaklık ve nem değerleri: "); //Ekrana Sıcaklık ve nem değerleri yazılır. 
Serial.print((int)sicaklik); //okunan sıcaklık değeri ekrana yazdırılır. 
Serial.print("C, ");
Serial.print((int)nem); //okunan nem değeri ekrana yazdırılır. 
Serial.println("%");
if(nem<=50) //Eğer nem değeri %50 in altında ise LED yanar ve buzzer ses verir. 
{
digitalWrite(ledPin, HIGH);
tone(buzzerPin, HIGH);
}
else //eğer nem değeri %50'in üstünde ise LED söner ve buzzer susar. 
{
digitalWrite(ledPin, LOW);
noTone(buzzerPin);
}
delay(2000); //sensörden her 2 sn de bir veri okuması yapılır. 
}


