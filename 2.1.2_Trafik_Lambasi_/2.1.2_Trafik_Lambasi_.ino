
int kirmiziPin = 8; //pin numaraları tanımlanır. 
int sariPin = 9;
int yesilPin = 10;


// ledleri çıkış olarak tanımlıyoruz
void setup() {

pinMode(kirmiziPin, OUTPUT);
pinMode(sariPin, OUTPUT);
pinMode(yesilPin, OUTPUT);

}

void loop() {

digitalWrite(kirmiziPin, HIGH); // öncelikle kırmızı led yanıyor
delay(5000); // 5 saniye bekler

digitalWrite(sariPin, HIGH); // sarı led yanar
delay(2000); // 2 saniye bekler

// şimdi yeşil ledi yakarak kırmızı ve sarı ledi söndürüyoruz

digitalWrite(yesilPin, HIGH);
digitalWrite(kirmiziPin, LOW);
digitalWrite(sariPin, LOW);
delay(5000);


// sarı ledi yakıp yeşil ledi söndürüyoruz
digitalWrite(sariPin, HIGH);
digitalWrite(yesilPin, LOW);
delay(2000);
digitalWrite(sariPin, LOW); // sarı led söner ve döngü baştan başlar

}
