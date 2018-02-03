// Kodun çalışması için gerekli olan kütüphaneler eklenir.
#include <SPI.h>
#include <SD.h>
//CS pin olarak 10  nolu dijital pin atanır. 
const int CSpin = 10;

File dosya; //dosya isminde SD kart nesnesi oluşturulur. Tüm SD kart fonksiyonların başında bu nesne ismi getirilir. 
File dosya1;
void setup() {
// Seri veri iletişimi başlatılır ve seri port ekranın açılması beklenir.
Serial.begin(9600);
while (!Serial) {
; // Seri portun bağlanması beklenir. USB portun bilgisayara takılı olması gerekir. 
}

Serial.print("SD kart başlatılıyor...");
if (!SD.begin(CSpin)) { //Eğer kart başlatılamazsa uyarı verir.
Serial.println("SD kart başlatılamadı.!");
return;
}
Serial.println("SD kart hazır."); //kart başlatmada sıkıntı çıkmazsa bu uyarı yazdırılır.

// deneme.txt ve deneme1.doc isminde bir dosya açılır. open komutunun özelliğinden dolayı dosya ismi mevcut olmasa da oluşturulmaktadır. 
dosya = SD.open("deneme.txt", FILE_WRITE);
dosya1 = SD.open("deneme1.doc", FILE_WRITE);
// dosyalar açıldığında, yazma işlemi başlar
if (dosya) {
Serial.print("deneme.txt ve deneme1.doc dosyasına bilgi yazılmaktadır...");
dosya.println("Arduino Dünyası'na hoş geldiniz. Arduino ile yapabilecekleriniz hayal dünyanız ile sınırlıdır.");
dosya1.println("Mehmet Akif Ocak ve Alper Efe");
// dosyalar kapatılır:
dosya.close();
dosya1.close();
Serial.println("yazma işlemi tamamlandı.");
} else {
// eğer dosyalar açılamaz ve yazma işlemi yapılamazsa, hata verir:
Serial.println("dosyalar açılamadı. Yazma işleminde hata");
}
//yazma işlemi burda bitti. dosyaya yazılan bilgilerin okunma işlemi başlar. 
// okuma için dosya tekrar açılır:
dosya = SD.open("deneme.txt");
dosya1 = SD.open("deneme1.doc");
if (dosya) {
Serial.println("");
Serial.println("Dosyalardan okunan bilgiler:");

while (dosya.available() ) { //Dosyadan okunabilen herhangi bir bayt olup olmadığını kontrol edilir. 
Serial.write(dosya.read());} //dosyada okunan bilgiler yazdırılır. 

while (dosya1.available() ) { //Dosyadan okunabilen herhangi bir bayt olup olmadığını kontrol edilir. 
Serial.write(dosya1.read());  //dosyada okunan bilgiler yazdırılır. 
}
// dosyalar kapanır:
dosya.close();
dosya1.close();
} else {
// eğer dosya açılamazsa, hata verir: 
Serial.println("Dosyalar okunamadı");
}
}

void loop() {
// yazma ve okuma işlemi bir defa yapıldığı için döngü kullanılmamıştır.
}


