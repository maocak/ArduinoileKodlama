#include <SoftwareSerial.h>  //kütüphaneler eklenir.
#include <Wire.h>
SoftwareSerial BTserial(0,1); // RX and TX pins
int kirmiziLEDpin = 9; //LEDlerin pin numaraları atanır.
int yesilLEDpin = 10;
int maviLEDpin = 11;

String RGB = "";
String RGB_onceki = "255.255.255";
String ON = "ON";
String OFF = "OFF";
boolean RGB_tamam = false;

void setup()
{
pinMode (kirmiziLEDpin, OUTPUT); //kırmızı LED pin çıkış olarak tanımlanır.
pinMode (yesilLEDpin, OUTPUT);   //yeşil LED pin çıkış olarak tanımlanır.
pinMode (maviLEDpin, OUTPUT);    //mavi LED pin çıkış olarak tanımlanır. 
Serial.begin(9600); //modülün iletişim hızı belirlenir.
BTserial.begin(9600);
RGB.reserve(30);
}

void loop()
{
while(BTserial.available())  //eğer porttan herhangi bir veri girişi olursa...
{
char c = (char)BTserial.read();  //modülden seri iletişim okunur ve c isimli değişkene atanır.
if(c == ')')
{
RGB_tamam = true;
}else{
RGB += c;
}
}
if(RGB_tamam)
{
Serial.print("RGB LED değeri:");
Serial.println(RGB);
if(RGB==ON)
{
RGB = RGB_onceki;
RGB_LED();
}
else if(RGB==OFF)
{
RGB = "0.0.0";
RGB_LED();
}else{
RGB_LED();
RGB_onceki = RGB;
}
RGB = "";
RGB_tamam = false;
}
}
void RGB_LED()
{
int SP1 = RGB.indexOf(' ');
int SP2 = RGB.indexOf(' ', SP1+1);
int SP3 = RGB.indexOf(' ', SP2+1);
String R = RGB.substring(0, SP1);
String G = RGB.substring(SP1+1, SP2);
String B = RGB.substring(SP2+1, SP3);
//Kullandığınız RGB'in ortak anot ya da ortak katot olma durumuna göre...
//analogWrite(kirmiziLEDpin, (R.toInt()));//eğer renkler ters çalışırsa aktif hale getirin 
//analogWrite(yesilLEDpin, (G.toInt()));//ve aşağıdaki 3 satırı pasif yapın...
//analogWrite(maviLEDpin, (B.toInt()));
analogWrite(kirmiziLEDpin, (255-R.toInt()));//eğer renkler ters çalışırsa aktif hale getirin...
analogWrite(yesilLEDpin, (255-G.toInt()));//ve yukardaki 3 satırı pasif yapın...
analogWrite(maviLEDpin, (255-B.toInt()));
}
