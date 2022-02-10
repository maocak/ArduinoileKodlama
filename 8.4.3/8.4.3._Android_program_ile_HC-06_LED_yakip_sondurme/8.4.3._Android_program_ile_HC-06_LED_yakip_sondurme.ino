#define ledpin 13 //LED pini tanımlanır. 
int durum = 0; //durum değişkenine ilk değer atanır.

void setup() {
pinMode(ledpin, OUTPUT); //LED pini çıkış olarak tanımlanır.
digitalWrite(ledpin, LOW); //LEDin ilk durumu LOW(sönük) olarak ayarlanır. 
Serial.begin(9600); //seri veri iletişimi başlatılır.
}

void loop() {
if(Serial.available() > 0){ //Eğer seri port ekranından giriş yapılırsa...
durum = Serial.read(); //girilen değer durum adlı değişkene atanır.
}

if (durum == '0') {
digitalWrite(ledpin, LOW); // //Girilen değer 0 ise LED söner.
durum = 0;
}
else if (durum == '1') {
digitalWrite(ledpin, HIGH); //Girilen değer eğer h ise LED yanar.
durum = 0;
}
delay (50);
} 
