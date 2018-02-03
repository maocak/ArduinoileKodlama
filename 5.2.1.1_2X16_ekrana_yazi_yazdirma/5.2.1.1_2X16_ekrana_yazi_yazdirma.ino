#include <LiquidCrystal.h> //LCD kütüphane eklenir. 

const int RS = 12, enable = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7); //LCD pin uçları tanımlanır.

//yuz karakteri binary olarak diziye atanır. 
byte yuz[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};
//Ş karakteri binary olarak diziye atanır.  
byte se[8] = {
  0b01110,
  0b10001,
  0b10000,
  0b01110,
  0b00001,
  0b10001,
  0b01110,
  0b00100
};
//ğ karakteri binary olarak diziye atanır. 
byte yumusakg[8] = {
 0b01110,
  0b00000,
  0b01110,
  0b10001,
  0b01111,
  0b00001,
  0b10001,
  0b01110
};
//Ö karakteri binary olarak diziye atanır. 
byte o[8] = {
  0b01010,
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};
//Ç karakteri binary olarak diziye atanır. 
byte ce[8] = {
  0b01110,
  0b10001,
  0b10000,
  0b10000,
  0b10000,
  0b10001,
  0b01110,
  0b00100
};
//İ karakteri binary olarak diziye atanır. 
byte i[8] = {
  0b00100,
  0b00000,
  0b01110,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b01110
};
//Ü karakteri binary olarak diziye atanır. 
byte inceu[8] = {
  0b01010,
  0b00000,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};
//ı karakteri binary olarak diziye atanır. 
byte kalini[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b01100,
  0b00100,
  0b00100,
  0b00100,
  0b01110
};
void setup()
{
lcd.begin(16,2); //LCDin sütun ve satır sayıları tanımlanarak başlatılır. 

// yuz karakteri oluşturulur
lcd.createChar(1, yuz);
// Ş karakteri oluşturulur
lcd.createChar(2, se);
// ğ karakteri oluşturulur
lcd.createChar(3, yumusakg);  
// Ö karakteri oluşturulur
lcd.createChar(4, o);  
// Ç karakteri oluşturulur
lcd.createChar(5, ce);  
// İ karakteri oluşturulur
lcd.createChar(6, i);  
// Ü karakteri oluşturulur
lcd.createChar(7, inceu);  
// ı karakteri oluşturulur
lcd.createChar(8, kalini); 
}

void loop(){
int i;

lcd.setCursor(0,0); // Yazma işlemi (0,0) sol üst köşeden başlayacak şekilde tanımlanır. 
lcd.print("Arduino Dunyasi"); //Ekranda ilk yazı görünür. 
 
lcd.cursor(); // İmleç yazının yanında çizgi şeklinde(_) belirir.
delay(3000);  //Görünme işlemi 3 saniye söner
lcd.noCursor(); //imleç kapatılır.
delay(500);  //1 saniye beklenir

 
lcd.clear(); //Ekran temizlenir
lcd.setCursor(0,0);
lcd.print("Projeleri yapmak"); //Ekrana 2.yazı olan "Projeleri yapmak daha kolay" gelir
lcd.setCursor(0,1);
lcd.print("daha kolay");
lcd.blink();// Yazının yanında imleç yanıp söner 
delay(3000); //yanıp sönme işlemi 3 saniye söner
lcd.noBlink(); //imleç kapatılır. 
delay(1000); //1 saniye beklenir

lcd.clear(); //ekran temizlenir.
lcd.setCursor(4, 1);
lcd.write((byte)1); //gülenyüz (Ekranda (sütun=4,satır=1) dan başlayarak yan yana gülenyüz,Ş,ğ,Ö,Ç,İ,Ü,ı karakterleri yazdırılır.)
lcd.write((byte)2); // Ş
lcd.write((byte)3);  //ğ
lcd.write((byte)4);  //Ö
lcd.write((byte)5);  //Ç
lcd.write((byte)6);  //İ
lcd.write((byte)7);  //Ü
lcd.write((byte)8);  //ı
delay(9000);  //9 saniye beklenir. 
lcd.clear();  //Ekran temizlenir. 

lcd.setCursor(5, 0);
lcd.print("Sen de dene"); //Sen de dene yazısı ilk satır ve sağa dayalı olarak yazılır
delay(2000);  //2 saniye beklenir. 
lcd.clear();  //Ekran temizlenir.

lcd.setCursor(16, 1); //Konum (sütun=16, satır=1) dan başlar..
 
lcd.autoscroll(); //yapabilirmisin yazısı (16,1) den başlayarak 10 kere otomatik kaydırma yapılır.
for (int i = 0; i < 6; i++) {
lcd.print("yapabilirsin");
delay(750); //her geçişte 0,75 saniye bekler.
}
lcd.noAutoscroll(); //otomatik kaydırma kapatılır. 
delay(2000); //2 saniye bekler. 

lcd.clear(); //Ekran temizlenir.
 
lcd.print("Hadi baslayalim "); //Hadi başlayalım yazısı karakter boyutu olan 16 karakter sola kaydırılır.
for (int i = 0; i < 16; i++) {    
// bir karakter sola kaydırılır
lcd.scrollDisplayLeft();
// 0,35sn geçikme yaşanır.
delay(350);
}
for (int i = 0; i < 32; i++) { //yazı kendi karakter boyutu+ekran satır boyutu=32 karakter sağa kaydırılır.
// bir karakter sağa kaydırılır.
lcd.scrollDisplayRight();
//Her kayma arasında 0,15 saniye geçikme yaşanır.
delay(150);
}
for (int i = 0; i < 16; i++) { //yazı tekrar 16 karakter sola kaydırılır.
// bir karakter sola kaydırılır
lcd.scrollDisplayLeft();

delay(150); //Her kayma arasında 0,15 saniye geçikme yaşanır.
} 
delay(3000); //3 saniye bekler. 
lcd.clear(); //Ekran temizlenir. 

}
