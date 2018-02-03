#include <Servo.h>  //servomotor kütüphanesi koda eklenir.                                     

Servo servomotor; //servomotor nesnesi oluşturulur. 
 
int durum = 0; //durum ilk değeri 0 atanır. 

void setup() {
Serial.begin(9600); //seri veri iletişimi başlatılır. 
servomotor.attach(9); //servomotor 9 nolu dijital pine bağlanır. 
}

void loop() {
int sensordeger = analogRead(A0); //A0 pininden yağmur sensörü değeri okunur. 
Serial.println(sensordeger);  //Okunan değer  seri port ekranına yazdırılır. 
if (sensordeger < 570) //sensör değeri eşik değeri olan 570dan küçük duruma gelirse...
{
for (durum = 0; durum <= 160; durum += 1) { //servomotor 0 dereceden 160 dereceye 1 derecelik adımlarla hareket eder
// in steps of 1 degree
servomotor.write(durum);
delay(7);
}
for (durum = 160; durum >= 0; durum -= 1) { //Tersine olarak servomotor 160 dereceden 0 dereceye doğru 1 derecelik adımlarla hareket eder. 
servomotor.write(durum);              
delay(7);                    
}
}
else { //sensör değeri eşik değeri olan 570 den küçük durumda değilse servomotor 15 dereceye döner. 
servomotor.write(15);
}
}

