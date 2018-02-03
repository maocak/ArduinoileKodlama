const int buzzerpin=9; //Buzzer pin tanımlanır
int ledpin=3; //LED pini tanımlanır. 
int lasersensorpin=6; //Lazer sensör pini tanımlanır.
int ldrpin=A0; //LDR pini tanımlanır. 
int deger; //deger isimli bir değişken atanır. 
void setup() {

Serial.begin(9600);  //seri veri alışverişi başlatılır. 
pinMode(buzzerpin, OUTPUT); //Buzzer pini çıkış olarak tanımlanır. 
pinMode(lasersensorpin, OUTPUT); //Lazer sensör pini tanımlanır. 
pinMode(ledpin, OUTPUT);  //LED pini tanımlanır. 
}

void loop() {

digitalWrite(lasersensorpin, HIGH); //Lazer sensör çalıştırılır ve hazır hale getirilir. 
deger =analogRead(A0); //LDR pininden analog değer okunur. 
Serial.println(deger);  //Okunan analog değer seri port ekranına yazdırılır. 
while(deger <800)  //Eğer analog değer eşik değer olan 800 altına düşerse...
{
tone(buzzerpin, 440);  //Buzzer ses verir. 
delay(50); 
noTone(buzzerpin); //delay ve noTone, buzzerin kesikli şekilde(alarm) ses vermesini sağlar. 
digitalWrite(ledpin, HIGH); //LED yanar. 
delay(100); // Bu delay LED'in devamlı olarak değil, blink olarak yanmasını sağlar. 
digitalWrite(ledpin,LOW);
}
delay(100); //Her 0.1 saniyede sensörden okuma yapılır. 
}
