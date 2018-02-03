#include <SPI.h>  //2 adet kütüphane kullanılmaktadır. 
#include <MFRC522.h>

#define resetpin  9  //SPI protokolü için kullanılacak sinyal pinlerin ataması yapılır.
#define SSpin  10         

MFRC522 mfrc522(SSpin, resetpin);  // RFID okuyucu(MFRC522) nesnesi oluşturulur. 

void setup() {
Serial.begin(9600);   // seri veri iletişimi başlatılır. 
SPI.begin();      // SPI iletişim protokolü başlatılır.
mfrc522.PCD_Init();   // RFID okuyucu bu komut ile başlatılır. (PCD ile MFRC522 aynı şeyi temsil eder)
mfrc522.PCD_DumpVersionToSerial();  // PCD/MFRC522 kart okuyucunun detayları gösterilir.
Serial.println("KARTI OKUYUCUYA YAKLAŞTIRINIZ!");
}

void loop() {
// yeni kartlar arar
if ( ! mfrc522.PICC_IsNewCardPresent()) {//eğer yeni PICC/kart kullanılırsa 1 döner ve program devam eder...
return; //eğer yeni bir kart kullanılmazsa 0 döner, ve loop un başına döner...
}
// okutulan kartın seri numarası seçilir ve MFR522 çipinin içine yazılır. Bu durumda program 1 döndürür.
if ( ! mfrc522.PICC_ReadCardSerial()) {
return; //eğer yeni bir seri numarası yoksa program 0 döndürür ve loop un başına döner. 
}

Serial.println("Okunan kartın seri numarası(Card UID), SAK numarası(Card SAD, kart türü(PICC type), ve veri blokları(sector block) şu şekildedir:");
mfrc522.PICC_DumpToSerial(&(mfrc522.uid));  // Kart hakkında bilgi dökümünü veren komut çalıştırılır. 
}
