// trig,  echo, buzzer ve LED için pin numaraları belirlenir. 
const int trigpin = 13;
const int echopin = 12;
const int buzzer = 11;
const int ledpin = 10;
// sure ve uzaklık isimli değişkenler tanımlanır. 
long sure;
int uzaklik;


void setup() {
pinMode(trigpin, OUTPUT); // trig pini çıkış olarak tanımlanır. 
pinMode(echopin, INPUT); // echo pin giriş olarak tanımlanır. 
pinMode(buzzer, OUTPUT);//buzzer pini çıkış olarak tanımlanır. 
pinMode(ledpin, OUTPUT); //ledpin çıkış olarak tanımlanır.
Serial.begin(9600); // seri veri iletişimi başlatılır. 
}


void loop() {
// trigpin ucu 0 yapılarak temizlenir
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
// trigpin ucu 10 mikro saniye HIGH durumunda bırakılarak sinyal yollanır. 
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW); //trig pin ucu tekrar LOW konumuna alınarak kapatılır. 
//gidip gelen sinyal echo pin ucu tarafından okunur, okunan değer mikrosaniye cinsinden döndürülür. 
sure = pulseIn(echopin, HIGH);
// uzaklik 1. formül kullanılarak hesaplanır. 
uzaklik= sure*0.034/2;
if (uzaklik <= 5){ // eğer uzaklık 5 cm in altında ise buzzer ses verir, LED yanar. 
tone(buzzer, 440);
digitalWrite(ledpin, HIGH);
}
else{
noTone(buzzer); //eğer uzaklık 5 cm in üstünde ise buzzer ses vermez, LED yanmaz. 
digitalWrite(ledpin, LOW);
}
// Hesaplanan uzaklık seri port ekranına yazdırılır. 
Serial.print("Uzaklık: ");
Serial.print(uzaklik);
Serial.println(" cm");
}


