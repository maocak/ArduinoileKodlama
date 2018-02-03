//trigger pin, echo pin ve kırmızı ve yeşil LED pinleri tanımlanır. 
#define trigPin 13
#define echoPin 12
#define kirmiziLED 11
#define yesilLED 10

void setup() {
Serial.begin (9600);//seri veri iletişimi başlatılır. 
pinMode(trigPin, OUTPUT); //trigger pini çıkış olarak tanımlanır.(Trigger pinden çıkan sinyal echo pinine girer.)
pinMode(echoPin, INPUT);  //echo pini giriş olarak tanımlanır. 
pinMode(yesilLED, OUTPUT); //yeşil ve kırmızı LED ler çıkış olarak tanımlanır. 
pinMode(kirmiziLED, OUTPUT);
}

void loop() { 
long sure, uzaklik; //süre ve uzaklık isimli 2 tane değişken tanımlanır. 
digitalWrite(trigPin, LOW);  // trigger çıkışı sinyal yollamadan önce 0 durumuna getirilir. 
delayMicroseconds(2); // 2ms beklenir. 
digitalWrite(trigPin, HIGH); //trigger çıkışından sinyal yollanır. 
delayMicroseconds(10); // 10 sn yollanır. Bunun nedeni yollanan sinyallerin karışmaması için
digitalWrite(trigPin, LOW); //trigger çıkışı tekrar 0 lanarak sinyal kesilir. 
sure = pulseIn(echoPin, HIGH); //trigger çıkışı ile yollanan sinyal HIGH ile okunur ve sinyalin uzunluğu mikrosaniye cinsinden döndürülür
uzaklik = (sure/2) / 29.1; //sinyalin gidip gelme süresinin yarısı alınır. Ve sonra, santimetre başına düşen mikro saniye süresine(29.1) bölünür. 
if (uzaklik < 4) {  // Uzaklık 4cm altına düşürse kırmızı LED yanar, yeşil LED söner. 
digitalWrite(kirmiziLED,HIGH); // 
digitalWrite(yesilLED,LOW);
}
else {
digitalWrite(kirmiziLED,LOW); //Uzaklık 4cm'den büyük 200 cm den küçükse kırmızı LED söner, yeşil LED yanar. 
digitalWrite(yesilLED,HIGH);
}
if (uzaklik >= 200 || uzaklik <= 0){ //Uzaklık 200cm in üstünden ise "Ölçülen uzaklık sınırların dışında" diye uyarı verir. 
Serial.println("Ölçülen uzaklık sınırların dışında");
}
else {
Serial.print(uzaklik);
Serial.println(" cm");
}
delay(500); 
}
