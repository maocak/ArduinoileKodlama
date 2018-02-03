// Kodun çalışması için gerekli olan kütüphaneler eklenir. 
#include <SPI.h>
#include <SD.h>

// SD kartın çalışması için gerekli olan kütüphanedeki fonksiyonları kullanmak için gerekli olan değişkenler tanımlanır. 
Sd2Card SDkart;  //SD kart değişkeni
SdVolume dosya;  //dosya değişkeni
SdFile kok;   //kök dizinindeki dosyaları listelemek için kullanılacak kok değişkeni

const int CSpin = 10;

void setup() {
// Seri veri iletişimi başlatılır ve seri port ekranın açılması beklenir. 
Serial.begin(9600);
while (!Serial) {
; // Seri portun bağlanması beklenir. USB portun bilgisayara takılı olması gerekir. 
}

Serial.print("\nSD kart başlatılıyor...");
// Kütüphaneden başlatma komutu kullanılır. we'll use the initialization code from the utility libraries
// Bu uygulamada sadece kartın çalışıp çalışmadığı test edilmektedir. 
if (!SDkart.init(SPI_HALF_SPEED, CSpin)) {
Serial.println("SD kart başlatılamadı. Aşağıdakileri kontrol edin:");
Serial.println("* Kart doğru takıldı mı?");
Serial.println("* Kablolama doğru mu?");
Serial.println("* Chipselect(CS)için doğru pin numarası girildi mi?(UNO'da 10.pin olmalıdır)");
return;
} else {
Serial.println("Kablolama doğru ve SD kart hazır.");
}

// SD kart türü seri port ekrana yazdırılır. 
Serial.print("\nSD kart türü: ");
switch (SDkart.type()) {
case SD_CARD_TYPE_SD1:
Serial.println("SD1");
break;
case SD_CARD_TYPE_SD2:
Serial.println("SD2");
break;
case SD_CARD_TYPE_SDHC:
Serial.println("SDHC");
break;
default:
Serial.println("Bilinmiyor.");
}
// Hafıza boyutu ve  dosya türü belirlenir. Desteklenen dosya türü FAT16 ya da  FAT32 olmalıdır. 
if (!dosya.init(SDkart)) {
Serial.println("FAT16/FAT32 dosya türü bulunamadı.\nSD kartın düzgün formatlandığından emin olunuz");
return;
}
// Dosya türü ve kart boyutu/hacmi okunur
uint32_t boyut;
Serial.print("\nDosya türü: FAT");
Serial.println(dosya.fatType(), DEC);
Serial.println();

boyut = dosya.blocksPerCluster();    // kümelere blokların toplamından oluşur. 
boyut *= dosya.clusterCount();       // Kaç küme olduğu sayılır
boyut *= 512;                            // SD kartların her zaman 512 baytlık bloklardan oluşur. 
Serial.print("SD kart boyutu (bayt): ");
Serial.println(boyut);
Serial.print("SD kart boyutu (Kilobayt): ");
boyut /= 1024;
Serial.println(boyut);
Serial.print("SD kart boyutu (Megabayt): ");
boyut /= 1024;
Serial.println(boyut);

Serial.println("\SD kartta bulunan dosyalar (ismi, tarih ve boyut(bayt): ");
kok.openRoot(dosya);

// Kartta bulunan tüm dosyalar isim, tarih ve boyutuyla beraber listenir. 
kok.ls(LS_R | LS_DATE | LS_SIZE);
}

void loop(void) {

}
