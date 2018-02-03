int kirmiziled = 10; //kırmızı LED pini tanımlanır. 
int yesilled = 9; //yeşil LED pini tanımlanır. 
int buzzer = 8; //buzzer pini tanımlanır. 
int sensor = A0; //sensör pini tanımlanır. 
// eşik Analog değer 400 olarak atanır. 
int esikdeger = 400;

void setup() {
pinMode(kirmiziled, OUTPUT); //kırmızı LED, yeşil LED ve buzzer pinleri çıkış olarak tanımlanır.
pinMode(yesilled, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(sensor, INPUT); //sensör pini giriş olarak tanımlanır.
Serial.begin(9600); //seri veri alışverişi başlatılır
}

void loop() {
int deger = analogRead(sensor); //analog çıkıştan okunan büyüklük deger isimli değişkene atanır. 
Serial.print("MQ-2 Okunan analog değer ");
Serial.println(deger); //sensörden okunan değer seri port ekranına yazdırılır. 
// Eğer sensörden okunan değer, eşik değeri geçerse...
if (deger > esikdeger)
{
digitalWrite(kirmiziled, HIGH); //kırmızı LEd yanar
digitalWrite(yesilled, LOW); //yeşil LED söner
tone(buzzer, 440); //buzzer ses çıkarır
}
else
{
digitalWrite(kirmiziled, LOW); //eşik değeri aşılmazsa kırmızı LED söner
digitalWrite(yesilled, HIGH);  //yeşil LED yanar
noTone(buzzer); //buzzer ses çıkarmaz
}
delay(100); //0.1 sn aralıkla sensörden değerler okunur. 
}
