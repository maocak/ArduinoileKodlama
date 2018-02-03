#define LED 8          // LED'in bağlanacağı pin 8 numaralı pin olarak tanımlanır. 
char karaktergir= 0;         // karaktergir fonksiyonunun ilk değeri 0 olarak atanır. 

void menuyazdir(void) //Menüyü ekrana yazan fonksiyon  
{ 
Serial.println("Karakter listesi: ");
Serial.println("r/R: Menüyü getir:");  
Serial.println("q/Q: LED yanar");
Serial.println("e/E: LED söner");
Serial.println("w/W: LED durumu");  
}

void setup(){
Serial.begin(9600);   // Seri port ekranı 9600 baud'da açılır.
pinMode(LED, OUTPUT); // pin 13 LED çıkışı olarak tanımlanır.
Serial.flush();       // Ara bellek temizlenir
menuyazdir();         // menü ekrana yazdırılır.
}


void loop(){
if (Serial.available() >0){         // Ara bellek kontrol edilerek veri girişinin olup olmadığı kontrol edilir. Eğer seri porttan veri girişi 
//olursa ara belleğe alınarak hazır hale getirilir.
karaktergir = Serial.read();      // Seri port ekranından okunan karakter karaktergir adlı bir değişkene atanır.
Serial.flush();                    // Bir sonraki karakter okuma işlemi için arabellek temizlenir
switch (karaktergir) {
case 'q':// Şayet 'q' or 'Q' girilirse
case 'Q':                          
if (digitalRead(LED) == LOW){        // Şayet LED sönükse:
digitalWrite(LED,HIGH);      // LED'i yak.
Serial.println("LED yandı");
}
else {
Serial.println("LED zaten yanıyor!");
}
break;
case 'e': // Şayet 'e' or 'E' girilirse
case 'E':                          
if (digitalRead(LED) == HIGH){       // Şayet LED yanıyorsa
digitalWrite(LED,LOW);       // LED'i söndür.
Serial.println("LED söndü");
}
else {
Serial.println("LED zaten sönük!"); //
}
break;
case 'w': // Şayet  'w' or 'W' girilirse
case 'W':                         
if (digitalRead(LED) == HIGH){        // LED'in durumunu yaz.
Serial.println("LED durumu: yanıyor");
}
else 
{
Serial.println("LED durumu: sönük");
}
break;
case 'r':                          // Şayet "r" ya da "R" girilirse:
case 'R':
menuyazdir();                   // Menüyü ekrana yazdır
break;
default:                           
Serial.print(char(karaktergir));//Seri port ekranından girilen ve menüde olmayan karakter ekrana yazılır.
break;
}
}
}


