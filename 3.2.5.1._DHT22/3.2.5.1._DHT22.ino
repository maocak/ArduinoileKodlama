//Çiğ noktası sıcaklığının hesaplanması için kullanılacak formüller fonksiyon içinde hesaplanır. 
double cignoktasi(double sicaklik, double nem)// alınan ve t ve h değerleri sicaklik ve nem değişkeni olarak atanır ve formüllerde kullanılır.
{
double oran = 373.15 / (273.15 + sicaklik);
double RHS = -7.90298 * (oran - 1);
RHS += 5.02808 * log10(oran);
RHS += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / oran ))) - 1) ;
RHS += 8.1328e-3 * (pow(10, (-3.49149 * (oran - 1))) - 1) ;
RHS += log10(1013.246);
double buharbasinci = pow(10, RHS - 3) * nem;
double cignoktasicaklik = log(buharbasinci / 0.61078); 
return (241.88 * cignoktasicaklik) / (17.558 - cignoktasicaklik); //hesaplanan çiğ noktası sıcaklığı geri döndürülür.
}
#include "DHT.h" //DHT kütüphanesi çağrılır. 
#define DHTPIN 2 // Sensörün data pini tanımlanır. 
#define DHTTYPE DHT22 // //kullanılacak sensör türü DHT22 olarak atanır. Kütüphane aynı 
//zamanda DHT11 içinde çalıştığı için bunu belirtmemiz gerekir.
// DHT22 sensörü normal 16 Mhz Arduino için hazır hale getirilir. 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
Serial.println("DHT22 sensör hazır!");
dht.begin();//sensör başlatılır. 
}

void loop() {
// Değerler her 2sn de bir okunur. 
delay(2000);
// Nem değeri okunur.
float nem = dht.readHumidity();
// Sıcaklık Celcius olarak okunur. 
float sicaklikC = dht.readTemperature();
// Sıcaklık Fahrenayt olarak okunur. 
float sicaklikF = dht.readTemperature(true);
// ısı indeksi hesaplanır
// sensörden alınan değer Fahrenayt cinsindendir.
float isiindeksF = dht.computeHeatIndex(sicaklikF, nem);
float isiindeksC = dht.convertFtoC(isiindeksF);//Fahrenayt değeri celcius değerine dönüştürülür. 
Serial.print("Nem: ");
Serial.print(nem);
Serial.print(" %, ");
Serial.print("Sıcaklık: ");
Serial.print(sicaklikC);
Serial.print(" *C, ");
Serial.print("Isı indeksi: ");
Serial.print(isiindeksC);
Serial.print(" *C, ");
Serial.print("Çiğ noktası sıcaklığı (*C): ");
Serial.println(cignoktasi(sicaklikC, nem)); //Çiğ noktası sıcaklığını hesaplamak için sıcaklık(t) ve nem(h) değerleri 
//yukarda tanımlanan cignoktasi fonksiyonuna gönderilir. 
}


