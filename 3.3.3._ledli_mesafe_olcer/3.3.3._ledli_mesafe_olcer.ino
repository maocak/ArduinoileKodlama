//trig, echo ve LED pinlerin atamaları yapılır. 
#define trigpin 3 
#define echopin 2 
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;
//maksimum ve minimum uzaklık değerleri 250 cm ve 2 cm olarak atanır. 
int maksimumuzaklik = 250; 
int minimumuzaklik = 2;  
long sure, uzaklik; //sure ve uzaklık isminde değişkenler belirlenir. 
int ledzaman = 400; //ledzaman değişkenine 400 değeri atanır. 

void setup() {
Serial.begin (9600);  //seri veri iletişimi başlatılır. 
pinMode(trigpin, OUTPUT); //trig pini çıkış olarak tanımlanır. 
pinMode(echopin, INPUT); //echo pini giriş olarak tanımlanır. 
pinMode(led1, OUTPUT); //led1-led10 çıkış pinleri tanımlanır. 
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
pinMode(led10, OUTPUT);
}

void loop() {
digitalWrite(trigpin, LOW); //trig pini önce low sonra high yapılarak ucun sinyal yollaması hazır hale getirilir. 
delayMicroseconds(2); 
digitalWrite(trigpin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigpin, LOW); //bir sonraki sinyal yollama için trigpin tekrar LOW'a çekilir. 
sure = pulseIn(echopin, HIGH); //gidip gelen sinyalin zaman aralığı sure isimli değişkene atanır. 
uzaklik = sure/58.3; // 2 numaralı formül kullanılarak uzaklık cm cinsinden hesaplanır. 
if (uzaklik >= maksimumuzaklik) //eğer uzaklik 250 cm den büyükse seri port ekranına 250 cm den büyük yazar. 
{
Serial.println("250cm den büyük");
}
else if (uzaklik == 5)  //uzaklık 5 cm eşitse 1 LED yanıp sönmeye başlar. 
{
Serial.println("5 cm");
digitalWrite(led1, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
}
else if (uzaklik == 10) //uzaklık 10 cm eşitse 2 LED yanıp sönmeye başlar. 
{
Serial.println("10 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
}
else if (uzaklik == 15) //uzaklık 15 cm eşitse 3 LED yanıp sönmeye başlar. 
{
Serial.println("15 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}
else if (uzaklik == 20)  //uzaklık 20 cm eşitse 4 LED yanıp sönmeye başlar. 
{
Serial.println("20 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
}
else if (uzaklik == 25) //uzaklık 25 cm eşitse 5 LED yanıp sönmeye başlar. 
{
Serial.println("25 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
}
else if (uzaklik == 30) //uzaklık 30 cm eşitse 6 LED yanıp sönmeye başlar. 
{
Serial.println("30 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
}
else if (uzaklik == 35) //uzaklık 35 cm eşitse 7 LED yanıp sönmeye başlar. 
{
Serial.println("35 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led7, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
}
else if (uzaklik == 40)  //uzaklık 40 cm eşitse 8 LED yanıp sönmeye başlar. 
{
Serial.println("40 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led8, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
}
else if (uzaklik == 45) //uzaklık 45 cm eşitse 9 LED yanıp sönmeye başlar. 
{
Serial.println("45 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led9, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led9, LOW);
}
else if (uzaklik == 50) //uzaklık 50 cm eşitse 10 LED yanıp sönmeye başlar. 
{
Serial.println("50 cm");
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
digitalWrite(led5, HIGH);
digitalWrite(led6, HIGH);
digitalWrite(led7, HIGH);
digitalWrite(led8, HIGH);
digitalWrite(led9, HIGH);
digitalWrite(led10, HIGH);
delay(ledzaman);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
digitalWrite(led9, LOW);
digitalWrite(led10, LOW);
}
else if (uzaklik <= minimumuzaklik)//uzaklık 2 cm nin altında ise seriport ekranına 2 cmden küçük yazısı yazar. 
{
 Serial.println("2cm'den küçük");   
}
else {
Serial.print(uzaklik); 
Serial.println(" cm"); 
}
delay(100);   
}
