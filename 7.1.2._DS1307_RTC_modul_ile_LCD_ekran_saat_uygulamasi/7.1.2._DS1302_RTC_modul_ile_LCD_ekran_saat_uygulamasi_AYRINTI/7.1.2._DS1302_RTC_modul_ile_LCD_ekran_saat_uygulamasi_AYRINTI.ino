#include <MyRealTimeClock.h> //kütüphaneler koda eklenir. 
#include <Wire.h> 
#include <LiquidCrystal.h>

MyRealTimeClock myRTC(2, 3, 4); // CLK=6, DAT=7, RST=8
LiquidCrystal lcd (7, 8, 9, 10, 11, 12); //LCD pin uçları tanımlanır. 

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

void setup() {
Serial.begin(9600); //seri veri iletişimi başlatılır. 

lcd.begin(16, 2); //LCD ekran başlatılır. 
Wire.begin(); //Wire kütüphanesi başlatılır. 
//şimdiki zamanın aşağıdaki parametrelere doğru şekilde girilmesi gerekir. Format şu şekildedir:
// | saniye 00 | dakika 47 | saat 11 | haftanın kaçıncı günü |gün 13 |  ay 12 | yıl 2017 |
//Bu kod bir defa çalıştırıldıktan sonra, pasif yapılmalıdır. Modülün pili bittiğinde ya da modüle ilk defa tarih ve zaman bilgisi
//yükleneceği zaman kullanılır. 
//kodda haftanın günü için 1=pazartesi, salı=2, çarşamba=3, perşembe=4, cuma=5, cumartesi=6, pazar=7 kullanılmalıdır. 
myRTC.setDS1302Time(00, 39, 13, 5 , 15, 12, 2017);

// Ç karakteri oluşturulur
lcd.createChar(5, ce);  
}

void loop() {
// Zaman için değişken güncellemesi yapılır ve bilgilere erişim izni verilir.
myRTC.updateTime();
lcd.setCursor(2,0); //2.sütun, 1. satırdan itibaren yazmaya başlar. 
lcd.print(myRTC.hours); // saat yazdırılır
lcd.print(":");
if (myRTC.minutes < 10)  //10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan //küçük dakikaların başına 0 eklenir ve 2 basamaklı yapılır. 
{
lcd.print("0");
}
lcd.print(myRTC.minutes); // dakika yazdırılır
lcd.print(":");
if (myRTC.seconds < 10) //10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan //küçük saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
lcd.print("0");
}
lcd.print(myRTC.seconds); // saniye yazdırılır
lcd.print("  "); //2 karakter boşluk verilir. 
haftaningunu(myRTC.dayofweek); //aşağıda oluşturulan fonksiyona sayı değeri olarak 1-7 //arası haftanın gün değeri yollanır.

lcd.setCursor(3,1); //3.sütun, 2. satırdan itibaren yazmaya başlar. 
lcd.print(myRTC.dayofmonth); // gün yazdırılır
lcd.print("/"); 
lcd.print(myRTC.month); // ay yazdırılır
lcd.print("/");
lcd.print(myRTC.year); // Yıl yazdırılır
lcd.print(" ");
delay(1000); //1 saniye beklenir. 
}

void haftaningunu(int gun) //yukarıdaki fonksiyondan gelen değere göre gün LCD ekranda //yazdırılır. 
{
switch (gun)
{
case 1:
lcd.print("Pzt"); //
break;
case 2:
lcd.print("Sal");
break;
case 3:
lcd.write((byte)5);  //Ç harfi Türkçe karakter yazdırılır. 
lcd.print("ar");
break;
case 4:
lcd.print("Per");
break;
case 5:
lcd.print("Cum");
break;
case 6:
lcd.print("Cmt");
break;
case 7:
lcd.print("Paz");
break;
}
}
