#include <IRremote.h> //IR kütüphanesi eklenir. 
int IRpin = 11; //IR okuyucu pin atanır.

IRrecv iralici(IRpin);  //IR alıcı nesnesi oluşturulur. 
decode_results sonuclar;  //decode_results sınıfından sonuclar isimli bir nesne oluşturulur. 
//Bu nesne iralici tarafından kullanılacak olup, bilgileri decode etmeye yarar.

void setup()
{
Serial.begin(9600); //seri veri iletişimi başlatılır.
iralici.enableIRIn(); // IR okuyucu başlatılır. 
//7 bolumlu LED gösterge pinleri çıkış olarak tanımlanır.   
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
//Gösterge başladığınad - işareti gözükür. Bu bir defaya mahsustur. 
digitalWrite(2, HIGH);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
digitalWrite(6, HIGH);
digitalWrite(5, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
}

void loop() {
if (iralici.decode(&sonuclar))  //Eğer okuyucu tuşa basıldığını algılarsa...
{
Serial.println(sonuclar.value, HEX);  //işlenen kod seri port ekrana yazdırılır.
rakamlarIR(); //tuş basımından elde edilen değer, rakamlar isimli tanımlanan fonksiyona yollanır. 
iralici.resume(); // bir sonraki tuşa basılması beklenir.
}
}   

void rakamlarIR()
{
switch(sonuclar.value)  // Alınan kod koşul yardımıyla ilgili LEDi yakar.
{
case 0XFF6897: //0 rakamı gösterilir. 
digitalWrite(2, LOW);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
break;
case 0XFF30CF: //1 rakamı gösterilir.
digitalWrite(2, HIGH);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
digitalWrite(6, HIGH);
digitalWrite(5, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
break;
case 0XFF18E7: //2 rakamı gösterilir.
digitalWrite(2, LOW);
digitalWrite(8, LOW);
digitalWrite(7, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(3, HIGH);
break;
case 0XFF7A85: //3 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(8,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(3, HIGH);
digitalWrite(5, HIGH);
break;
case 0XFF10EF: //4 rakamı gösterilir.
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(5, HIGH);
digitalWrite(6,HIGH);
break;
case 0XFF38C7: //5 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(5, HIGH);
digitalWrite(8,HIGH);
break;
case 0XFF5AA5:  //6 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(8,HIGH);
break;
case 0XFF42BD: //7 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
break;
case 0XFF4AB5: //8 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(8,LOW);
digitalWrite(5,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(4,LOW);
break;
case 0XFF52AD:  //9 rakamı gösterilir.
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
break;
default: //Başka bir tuşa basıldığında "diğer tuşlara basıldı!" uyarısını verir. 
Serial.println("diğer tuşlara basıldı!");
}
delay(500);
}
