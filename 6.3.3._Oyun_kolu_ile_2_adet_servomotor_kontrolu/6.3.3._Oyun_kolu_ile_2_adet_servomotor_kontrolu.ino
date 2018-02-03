#include <Servo.h>  //servo motor kütüphanesi eklenir. 

Servo dikeyservomotor; // dikey servo motor için servo motor nesnesi oluşturulur. 
Servo yatayservomotor; // Yatay servo motor için servo motor nesnesi oluşturulur. 

const int ledpin = 4; // LED için pin no tanımlanır. 
const int butonpin = 2; //Oyun kolu butonu için pin tanımlanır. 
int butondurum ; //butondurum adlı değişken atanır.

int dikeypin = 0; // Oyun kolunun x değeri için analog giriş pini atanır. 
int yataypin = 1; // Oyun kolunun y değeri için analog giriş pini atanır.

int yataydeger; // x ekseninden okunacak değer için değişken tanımlanır. 
int dikeydeger; // y ekseninden okunacak değer için değişken tanımlanır.

void setup()
{
Serial.begin(9600); //Seri veri iletişimi başlatılır. 
  
pinMode (ledpin, OUTPUT); // LED pin giriş olarak tanımlanır. 
pinMode (butonpin, INPUT_PULLUP); // buton pin çıkış olarak tanımlanır.  
dikeyservomotor.attach(9); // dikey servomotor 9 nolu PWM pinine baplanır.
yatayservomotor.attach(10); // yatay servomotor 10 nolu PWM pinine baplanır. 
}

void loop()
{
butondurum = digitalRead (butonpin); //Oyun kolu butonunun değeri okunur. Değer basılmadığında 1, basıldığında 0 dır. 
if (butondurum == HIGH) {
digitalWrite (ledpin, LOW); //butona basılırsa LED yanar. 
}
else {
digitalWrite (ledpin, HIGH); //butona basılmazsa LED yanmaz. 
}
   
dikeydeger = analogRead(dikeypin); // Oyun kolunun yatay pozisyon analog değeri okunur.
dikeydeger = map(dikeydeger, 0, 1023, 0, 180); // Okunan analog değer 0-180 arası açısal değere dönüştürülür. 
dikeyservomotor.write(dikeydeger); // Dikey servo motor istenen pozisyona getirilir. 

yataydeger = analogRead(yataypin); // Oyun kolunun yatay pozisyon analog değeri okunur. 
yataydeger = map(yataydeger, 0, 1023, 180, 0); // Okunan analog değer 180-0 arası açısal değere dönüştürülür.
yatayservomotor.write(yataydeger); // Yatay servo motor istenen pozisyona getirilir. 
  
Serial.print("X: "); //okunan yatay açı değeri ekrana yazdırılır. 
Serial.print(yataydeger);
Serial.print(" | Y: ");  //okunan dikey açı değeri ekrana yazdırılır.
Serial.print(dikeydeger);
Serial.print(" | Button: ");
Serial.println(butondurum);  //oyun kolunun butonuna basılma durumuna ekrana yazdırır. 
delay(100); // servomotorların istenen değerlere gitmesi için zaman tanınır. 
}
