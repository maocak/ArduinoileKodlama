#include <MyRealTimeClock.h> //kütüphane koda eklenir. 

MyRealTimeClock myRTC(6, 7, 8); // CLK=6, DAT=7, RST=8 Arduino dijital pinlerine //bağlanır.

void setup() {
Serial.begin(9600); //seri veri iletişimi başlatılır. 

//şimdiki zamanın aşağıdaki parametrelere doğru şekilde girilmesi gerekir. Format şu şekildedir:
// | saniye 00 | dakika 47 | saat 11 | haftanın kaçıncı günü |gün 13 |  ay 12 | yıl 2017 |
//Bu kod bir defa çalıştırıldıktan sonra, pasif yapılmalıdır. Modülün pili bittiğinde ya da //modüle ilk defa tarih ve zaman bilgisi yükleneceği zaman kullanılır. 
//kodda “dayofweek” yani haftanın günü için 1=pazartesi, salı=2, çarşamba=3, perşembe=4, //cuma=5, cumartesi=6, pazar=7 kullanılmalıdır. 
myRTC.setDS1302Time(00, 57, 13, 5, 31, 12, 2021);
}

void loop() {

// Zaman için değişken güncellemesi yapılır ve bilgilere erişim izni verilir.
myRTC.updateTime();

Serial.print("Gün: ");
haftaningunu(myRTC.dayofweek); //aşağıda oluşturulan fonksiyona sayı değeri olarak 1-7 //arası haftanın gün değeri yollanır.
Serial.print(", Şimdiki Tarih ve Saat: "); 
Serial.print(myRTC.dayofmonth); // gün yazdırılır
Serial.print("/"); 
Serial.print(myRTC.month); // ay yazdırılır
Serial.print("/");
Serial.print(myRTC.year); // Yıl yazdırılır
Serial.print(" ");
Serial.print(myRTC.hours); // saat yazdırılır
Serial.print(":");
if (myRTC.minutes < 10)  //10 dan küçük dakikalar tek basamaklı gösterildiği için, 10 dan //küçük dakikaların başına 0 eklenerek 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.print(myRTC.minutes); // dakika yazdırılır
Serial.print(":");
if (myRTC.seconds < 10) //10 dan küçük saniyeler tek basamaklı gösterildiği için, 10 dan //küçük saniyelerin başına 0 eklenir ve 2 basamaklı yapılır. 
{
Serial.print("0");
}
Serial.println(myRTC.seconds); // saniye yazdırılır
delay(1000);
}

void haftaningunu(int gun) //yukarıdaki fonksiyondan gelen değere göre gün seri port ekranda //yazdırılır. 
{
switch (gun)
{
case 1:
Serial.print("Pazartesi"); //
break;
case 2:
Serial.print("Salı");
break;
case 3:
Serial.print("Çarşamba");
break;
case 4:
Serial.print("Perşembe");
break;
case 5:
Serial.print("Cuma");
break;
case 6:
Serial.print("Cumartesi");
break;
case 7:
Serial.print("Pazar");
break;
}
}
