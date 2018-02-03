#include<Servo.h>  //servo kütüphanesi dahil edilir. 

Servo servomotor;  //servo motor başlatılır. 
int buton1 = 2;  //2 ile 8 pinleri arası 7 adet buton pinleri atanır. 
int buton2 = 3;
int buton3 = 4;
int buton4 = 5;
int buton5 = 6;
int buton6 = 7;
int buton7 = 8;

int zaman = 50; //zaman değeri 50 olarak atanır. 
int deger=0;   //deger değişkeni ilk değer 0 atanır. 

void setup()  {
pinMode(buton1, INPUT); //buton pinleri çıkış olarak tanımlanır. 
pinMode(buton2, INPUT);
pinMode(buton3, INPUT);
pinMode(buton4, INPUT);
pinMode(buton5, INPUT);
pinMode(buton6, INPUT);
pinMode(buton7, INPUT);
  
servomotor.attach(9); //servo motor 9 nolu pine bağlanır.

}  
 
void loop()
{ 
deger = digitalRead(buton1); //buton1 e(en sağdaki buton) basıldığında 180 dereceye gider. 
if (deger == HIGH) 
{
servomotor.write(180); 
delay(zaman);
}
deger = digitalRead(buton2); //buton 2 e basıldığında 150 dereceye gider. 
if (deger == HIGH) 
{
servomotor.write(150); 
delay(zaman);
}
deger = digitalRead(buton3);  //buton 3 e basıldığında 120 dereceye gider.
if (deger == HIGH) 
{
servomotor.write(120); 
delay(zaman);
}
deger = digitalRead(buton4);
if (deger == HIGH) 
{
servomotor.write(90);  //buton 4 e basıldığında 90 dereceye gider.
delay(zaman);
}
deger = digitalRead(buton5);
if (deger == HIGH) 
{
servomotor.write(60);  //buton 5 e basıldığında 60 dereceye gider.
delay(zaman);
}
deger = digitalRead(buton6);
if (deger == HIGH) 
{
servomotor.write(30);  //buton 6 ya basıldığında 30 dereceye gider.
delay(zaman);
}
deger = digitalRead(buton7); //buton 7 ye(en soldaki buton) basıldığında 0 dereceye gider.
if (deger == HIGH) 
{
servomotor.write(0); 
delay(zaman);
}
}
