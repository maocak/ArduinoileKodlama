// LED'i açıp kapayacak buton pinleri tanımlanır
int butonacpin= 2;
int butonkapatpin = 3;
// LED için kullanılacak arduino dijital pini tanımlanır
int ledpin = 8;

void setup() {
// Led pini çıkış olarak tanımlanır
pinMode(ledpin, OUTPUT);
// LEDi açıp kapamak için kullanılacak buton pinleri dahili pullup direnci kullanılarak giriş olarak tanımlanır
pinMode(butonacpin, INPUT_PULLUP);
pinMode(butonkapatpin, INPUT_PULLUP);
}

void loop() {
// Eğer butonacpin 'in bağlı olduğu soldaki butonuna basılırsa butonacpin'i LOW olur ve koşul sağlandığından ledpin HIGH olur ve yanar
if(digitalRead(butonacpin) == LOW)
{
digitalWrite(ledpin, HIGH);
}
// Eğer butonkapatpin 'in bağlı olduğu sağdaki butonuna basılırsa butonkapatpin LOW olur ve koşul sağlandığından ledpin'i LOW olur ve söner
if (digitalRead(butonkapatpin)== LOW)
{
digitalWrite(ledpin, LOW);
}
}
