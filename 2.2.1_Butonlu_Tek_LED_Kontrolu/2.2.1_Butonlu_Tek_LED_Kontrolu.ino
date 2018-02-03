// pin numaralarını sabit olarak tanımlıyoruz
const int butonPin = 7; // butonun bağlı olduğu pin numarası
const int ledPin = 10; // LED'in bağlı olduğu pin numarası
int buttonDurumu = 0; // Buton girişinin durumu (HIGH veya LOW)

void setup() {
// Buton pinini giriş olarak ayarlıyoruz:
pinMode(butonPin, INPUT);
// LED pinini çıkış olarak ayarlıyoruz
pinMode(ledPin, OUTPUT);
}

void loop() {
// Buton durumunu oku
buttonDurumu = digitalRead(butonPin);
/* Butona basıldığında butonun durumu HIGH olacaktır. Bu durumda
LED çıkışını HIGH yapıyoruz. Tersi durumda ise LOW yapıyoruz
*/
if (buttonDurumu == HIGH) {
digitalWrite(ledPin, HIGH);
}
else {
digitalWrite(ledPin, LOW);
}
}
