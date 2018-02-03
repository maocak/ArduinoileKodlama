int yagmurpin = A0; //yağmur sensör pini tanımlanır. 
int yesilled = 6; //yeşil LED pini tanımlanır. 
int kirmiziled = 7; //kırmızı LED pini tanımlanır. 
// Eşik değeri istenildiğinde değiştirilebilinir. 
int esikdegeri = 500; //eşik değeri 500 olarak atanır. 

void setup(){
pinMode(yagmurpin, INPUT);//Yağmur sensörü pini çıkış olarak atanır. 
pinMode(yesilled, OUTPUT); //yeşil LED pini giriş olarak atanır. 
pinMode(kirmiziled, OUTPUT); //kırmızı LED pini giriş olarak atanır. 
digitalWrite(yesilled, LOW); //yeşil ve kırmızı LED'in ilk durumu LOW/sönük atanır. 
digitalWrite(kirmiziled, LOW);
Serial.begin(9600); //seri veri alışverişi başlatılır. 
}

void loop() {
// Analog pin A0'dan değer okunur
int sensordegeri = analogRead(yagmurpin);
Serial.print(sensordegeri);//okunan analog değer ekrana yazdırılır.
if(sensordegeri < esikdegeri){ //eğer sensör değeri eşik değeri 500'den küçükse ekrana Islak yazar ve kırmızı LED yanar.
Serial.println(" Islak");
digitalWrite(yesilled, LOW);
digitalWrite(kirmiziled, HIGH);
}
else { //okunan değer, eşik değeri olan 500'den büyükse ekrana Kuru yazar ve yeşil LED yanar. 
Serial.println(" Kuru");
digitalWrite(yesilled, HIGH);
digitalWrite(kirmiziled, LOW);
}
delay(500);//0.5 saniye bekleme
}
