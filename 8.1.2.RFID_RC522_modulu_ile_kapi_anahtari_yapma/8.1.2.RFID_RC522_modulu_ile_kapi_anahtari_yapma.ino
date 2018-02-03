#include "SPI.h" //4 adet kütüphane koda dahil edilir. 
#include "MFRC522.h"
#include <Servo.h>
#include <LiquidCrystal.h>

#define SSpin 10 //SPI protokolü için kullanılacak sinyal pinlerin ataması yapılır.
#define resetpin 9
#define kirmiziLEDpin 6 //LED pinleri tanımlanır
#define yesilLEDpin 7
#define buzzerpin 8  //buzzer pin tanımlanır. 
#define servopin 5  //servomotor için pin tanımlanır. 

LiquidCrystal lcd(A0, A1, A5, A4, A3, A2); //LCD ekran pin tanımlamaları yapılır. 
Servo servo; //servo motor için nesne oluşturulur. 
MFRC522 rfid(SSpin, resetpin); // RFID okuyucu pin numaraları tanımlanır. 
MFRC522::MIFARE_Key key; // RFID okuyucu(MFRC522) nesnesi oluşturulur.

void setup() {
Serial.begin(9600);  // seri veri iletişimi başlatılır. 
lcd.begin(16,2);   //LCD ekran başlatılır. 
SPI.begin();  // SPI iletişim protokolü başlatılır.
rfid.PCD_Init();  // RFID okuyucu bu komut ile başlatılır. (PCD ile MFRC522 aynı şeyi temsil eder)
pinMode(kirmiziLEDpin, OUTPUT); //Kırmızı LED pin çıkış olarak atanır. 
pinMode(yesilLEDpin, OUTPUT);   //Yeşil LED pin çıkış olarak atanır. 
pinMode(buzzerpin,OUTPUT);   //buzzer pin çıkış olarak atanır. 
servo.attach(servopin); //servo motor 5 nolu dijital pine bağlanır. 
}

void loop() {
lcd.clear(); //LCD ekran temizlenir. 
lcd.print("Hosgeldiniz!"); //program ilk çalıştırıldığında ekranın ilk satırında Hoşgeldiniz yazar. 
lcd.setCursor(0,1);
lcd.print("Karti okutunuz!"); //2.satırda Kartı okutunuz yazar. 
// yeni kartlar aranır
if ( ! rfid.PICC_IsNewCardPresent()) {//eğer yeni PICC/kart kullanılırsa 1 döner ve program devam eder...
return; //eğer yeni bir kart kullanılmazsa 0 döner, ve loop un başına döner...
}
// okutulan kartın seri numarası seçilir ve MFR522 çipinin içine yazılır. Bu durumda program 1 döndürür.
if ( ! rfid.PICC_ReadCardSerial()) {
return; //eğer yeni bir seri numarası yoksa program 0 döndürür ve loop un başına döner. 
}

String kartno = ""; //okutulan kartın seri numarası AA:AA:AA:AA formatında bir döngü içinde okutulur. 
for (byte i = 0; i < 4; i++) { //0dan 4e kadar döngü içinde kart numarasının karakterleri okunur. 
kartno +=
(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + 
String(rfid.uid.uidByte[i], HEX) + //hexedecimal olarak okunan string karakter dizisi yan yana + işareti ile getirilir.  
(i!=3 ? ":" : ""); //2 şerli karakterlerin arasında : karakteri yazılır. 
}
kartno.toUpperCase(); //tüm okunan karakterler büyük harfe dönüştürülür. 

Serial.print("Kart seri numarası: ");
Serial.println(kartno); //okunan kart nosu seri porta yazdırılır. 

servo.write(0); //Servo  0 derecede, kapı kapalı 

//eğer kullanılan kart doğru ID numarası içeriyorsa...
if (kartno.indexOf("1C:30:E7:AB")>=0) {
digitalWrite(yesilLEDpin, HIGH);  //yeşil LED yanar
digitalWrite(kirmiziLEDpin, LOW); //kırmızı LED yanar. 
tone(buzzerpin, 440,1000); //buzzer 1 saniye öter...
servo.write(180);   //servo kafası 180 dereceye gelir. kapı açık
lcd.clear();             //LCD ekran temizlenir ve...                       
lcd.print("ID dogru,kapi 5s"); //ekrana "ID doğru,5n sonra kapanacak" ifadesi gelir. 
lcd.setCursor(0,1);
lcd.print("sonra kapanacak!");

for(int i = 5; i > 0; i--) //döngü yardımıyla 5 saniye sayılır ve..
{
delay(1000);
}
servo.write(0); //kapı 0 dereceye geri döner.kapı kapalı
digitalWrite(yesilLEDpin, LOW); //yeşil LED söner
digitalWrite(kirmiziLEDpin, HIGH); //kırmızı LED yanar. 
}
else{
lcd.clear(); //eğer yanlış bir kart kullanılırsa...
lcd.print("Kart ID yanlis!"); //ekranda "Kart ID yanlış" yazar...
tone(buzzerpin, 440,500);  //buzzer yarım saniye ses çıkarır..
digitalWrite(yesilLEDpin, LOW);  //bu durumda yeşil LED sönük ve...
digitalWrite(kirmiziLEDpin, HIGH); //kırmızı LED yanık durumdadır..
servo.write(0); //servo kapalı durumdadır. 
delay(1000);  //1 saniye bekler...
}
rfid.PICC_HaltA(); //herhangi biRFID kart okutulana kadar okuyucu beklemeye geçer. 
rfid.PCD_StopCrypto1();  //RC522 çip beklemeye geçer.
}
