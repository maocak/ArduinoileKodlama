//I2C ve Wire kütüphanesi üzerinden bağlanan DS1307 RTC'yi kullanarak tarih ve saat işlevlerini yürüten kütüphaneler eklenir. 
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc; //RTC nesnesi oluşturulur. 

char daysOfTheWeek[7][12] = {"Pazar", "Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma", "Cumartesi"}; //7 gün 12 ay üzerinden 2 boyutlu bir dizi oluşturulur. 

void setup () {
Serial.begin(9600); //seri veri iletişimi başlatılır. 
if (! rtc.begin()) { // Eğer modül başlatılamazsa...
Serial.println("RTC modül bulunamadı");  //ekrana bu uyarı yazar. 
while (1); //programdan çıkılır. 
}

if (! rtc.isrunning()) {//Eğer modül başlatılıp ancak çalışmazsa...
Serial.println("RTC modül çalışmıyor!");  // ekrana bu uyarı yazar. 

// Eğer, RTC ilk defa kullanılıyorsa ya da pili değiştirildiyse bu kodun aktif hale getirilerek derleme anındaki bilgisayar saatinin RTC ye yazılması sağlanır. 
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
}

void loop () {

DateTime now = rtc.now(); //DateTime nesnesi RTC ye yazılan gün, ay,yıl haftanın günü, saat, dakika ve saniye bilgilerini alır. 
    
Serial.print(now.day(), DEC); //Seri port ekranına gün yazdırılır. 
Serial.print('/');
Serial.print(now.month(), DEC); //Seri port ekranına ay yazdırılır.
Serial.print('/');
Serial.print(now.year(), DEC);  //Seri port ekranına yıl yazdırılır.
Serial.print(" (");
Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);  //Seri port ekranına haftanın günü parantez içinde yazdırılır.
Serial.print(") ");
Serial.print(now.hour(), DEC); //Seri port ekranına saat yazdırılır.
Serial.print(':');
if (now.minute() < 10)//10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan küçük dakikaların başına 0 eklenir ve 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.print(now.minute(), DEC); //Seri port ekranına dakika yazdırılır.
Serial.print(':');
if (now.second() < 10)//10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan küçük saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.print(now.second(), DEC); //Seri port ekranına saniye yazdırılır.
Serial.println();
    
delay(1000); //bilgiler saniyede bir güncellenir. 
}
