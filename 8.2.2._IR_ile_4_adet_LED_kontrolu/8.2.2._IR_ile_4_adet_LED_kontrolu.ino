#include <IRremote.h> //IR kütüphanesi eklenir. 
 
int kizilotesiIR_pin = 3;  //IR okuyucu pin atanır. 
int kirmiziLEDpin = 6; //4 adet LED pinleri atanır. 
int yesilLEDpin = 7;
int sariLEDpin = 8;
int beyazLEDpin=5;
 
IRrecv iralici(kizilotesiIR_pin); //IR alıcı nesnesi oluşturulur. 
decode_results sonuclar;//decode_results sınıfından sonuclar isimli bir nesne oluşturulur. 
//Bu nesne iralici tarafından kullanılacak olup, bilgileri decode etmeye yarar.
 
void setup()
{

pinMode(kirmiziLEDpin,OUTPUT); //LED pinleri çıkış olarak tanımlanır. 
pinMode(yesilLEDpin,OUTPUT);
pinMode(sariLEDpin,OUTPUT);
pinMode(beyazLEDpin,OUTPUT);
Serial.begin(9600); //seri veri iletişimi başlatılır. 
iralici.enableIRIn(); // IR okuyucu başlatılır. 
}
 
void loop()
{
if (iralici.decode(&sonuclar)) //Eğer okuyucu tuşa basıldığını algılarsa...
{
Serial.println(sonuclar.value, HEX); //işlenen kod seri port ekrana yazdırılır. 
cevirIR(); //Alınan kod oluşturulan fonksiyona yollanır. 
iralici.resume(); // receive the next value
}
}
 
void cevirIR() // tuşa basılınca alınan kod koşul yardımıyla ilgili LEDi yakar. 
{
switch(sonuclar.value) //alınan kod eğer...
{
case 0xFF30CF:  //1 ise(FF30CF), kırmızı LED yanar. 
digitalWrite(kirmiziLEDpin,HIGH);
digitalWrite(yesilLEDpin,LOW);
digitalWrite(sariLEDpin,LOW);
digitalWrite(beyazLEDpin,LOW);
break;
case 0xFF18E7:  //2 ise(FF18E7), yeşil LED yanar. 
digitalWrite(kirmiziLEDpin,LOW);
digitalWrite(yesilLEDpin,HIGH);
digitalWrite(sariLEDpin,LOW);
digitalWrite(beyazLEDpin,LOW);
break;
case 0xFF7A85:  //3 ise(FF7A85), sarı LED yanar. 
digitalWrite(kirmiziLEDpin,LOW);
digitalWrite(yesilLEDpin,LOW);
digitalWrite(sariLEDpin,HIGH);
digitalWrite(beyazLEDpin,LOW);
break;
case 0xFF10EF:  //4 ise(FF10EF), beyaz LED yanar. 
digitalWrite(kirmiziLEDpin,LOW);
digitalWrite(yesilLEDpin,LOW);
digitalWrite(sariLEDpin,LOW);
digitalWrite(beyazLEDpin,HIGH);
break;
case 0xFF38C7: //5 ise(FF38C7), tüm LED ler yanar. 
digitalWrite(kirmiziLEDpin,HIGH);
digitalWrite(yesilLEDpin,HIGH);
digitalWrite(sariLEDpin,HIGH);
digitalWrite(beyazLEDpin,HIGH);
break;
case 0xFF5AA5: //6 ise(FF5AA5), tüm LEDler söner. 
digitalWrite(kirmiziLEDpin,LOW);
digitalWrite(yesilLEDpin,LOW);
digitalWrite(sariLEDpin,LOW);
digitalWrite(beyazLEDpin,LOW);
break;
default: //1-5 arası başka bir tuşa basıldığında "diğer tuşlara basıldı!" uyarısını verir. 
Serial.println("diğer tuşlara basıldı!");
}
delay(500);
}
