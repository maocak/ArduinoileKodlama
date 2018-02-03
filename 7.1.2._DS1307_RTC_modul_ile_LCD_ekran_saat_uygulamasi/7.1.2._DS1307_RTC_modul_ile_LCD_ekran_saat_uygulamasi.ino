//kütüphaneler koda eklenir. 
#include <Wire.h> 
#include "RTClib.h"
#include <LiquidCrystal.h>

RTC_DS1307 RTC; //RTC modül nesnesi oluşturulur. 
LiquidCrystal lcd (7, 8, 9, 10, 11, 12); //LCD pin uçları tanımlanır. 

void setup () {
Serial.begin(9600); //seri veri iletişimi başlatılır. 
lcd.begin(16, 2); //LCD ekran başlatılır. 
Wire.begin(); //Wire kütüphanesi başlatılır. 
RTC.begin();  //RTC modül başlatılır. 
//RTC başlatılamazsa bu uyarıyı verir. 
if (! RTC.isrunning()) {
Serial.println("RTC çalışmıyor!");
// Eğer, RTC ilk defa kullanılıyorsa ya da pili değiştirildiyse bu kodun aktif hale getirilerek derleme anındaki bilgisayar saatinin RTC ye yazılması sağlanır. 
RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
}

void loop () {
DateTime now = RTC.now(); //DateTime nesnesi RTC ye yazılan gün, ay,yıl haftanın günü, saat, dakika ve saniye bilgilerini alır. 
    
lcd.setCursor(0,0); //Ekranın sol üst köşesinden başlayarak SAAT yazısı yazar. 
lcd.print("SAAT: ");
lcd.print(now.hour(), DEC);  //DateTime nesnesinin okuduğu saat bilgisi ekrana yazdırılır. 
lcd.print(":");
if (now.minute() < 10)//10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan küçük dakikaların başına 0 eklenir ve 2 basamaklı yapılır. 
{
lcd.print("0");
}
lcd.print(now.minute(), DEC); //Dakika bilgisi ekrana yazdırılır. 
lcd.print(":");
if (now.second() < 10)//10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan küçük saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
lcd.print("0");
}
lcd.print(now.second(), DEC); //saniye bilgisi ekrana yazdırılır. 
    
lcd.setCursor(0,1); //sol alt köşeden başlayarak TARIH yazısı ekrana yazdırılır. 
lcd.print("TARIH:");
lcd.print(now.day(), DEC); //gün yazdırılır. 
lcd.print("/");
lcd.print(now.month(), DEC); //ay yazdırılır. 
lcd.print("/");
lcd.print(now.year(), DEC);  //yıl yazdırılır. 

delay(1000); //
}
