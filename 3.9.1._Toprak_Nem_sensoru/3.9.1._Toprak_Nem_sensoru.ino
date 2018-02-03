//led pinleri ve sensör pini tanımlanır.
int ledpin1 = 2;
int ledpin2 = 3;
int ledpin3 = 4;
int ledpin4 = 5;
int ledpin5 = 6; 
int topraknemsensorpin = 0;

void setup() {
// Seri iletişim başlatılır. 
Serial.begin(9600);
// LED pinleri çıkış olarak tanımlanır.
pinMode(ledpin1, OUTPUT);
pinMode(ledpin2, OUTPUT);
pinMode(ledpin3, OUTPUT);
pinMode(ledpin4, OUTPUT);
pinMode(ledpin5, OUTPUT);
}

void loop() {
// Analog A0 çıkışından okunan sayısal büyüklük, deger isimli değişkene atanır. 
int deger = analogRead(topraknemsensorpin);
Serial.println(deger); // Okunan değer seri port ekranına yazdırılır.   
  
if (deger >= 820)//okunan değer 820 analog değerden büyükse sadece 1 adet yeşil LED yanar. 
{
digitalWrite(ledpin1, HIGH);
digitalWrite(ledpin2, LOW);
digitalWrite(ledpin3, LOW);
digitalWrite(ledpin4, LOW);
digitalWrite(ledpin5, LOW);
}
else if (deger >= 615  && deger < 820)//değer bu aralıkta ise 2 adet yeşil LED yanar.
{
digitalWrite(ledpin1, HIGH);
digitalWrite(ledpin2, HIGH);
digitalWrite(ledpin3, LOW);
digitalWrite(ledpin4, LOW);
digitalWrite(ledpin5, LOW);
}  
else if (deger >= 410 && deger < 615) //değer bu aralıkta ise 3 adet yeşil LED yanar. 
{
digitalWrite(ledpin1, HIGH);
digitalWrite(ledpin2, HIGH);
digitalWrite(ledpin3, HIGH);
digitalWrite(ledpin4, LOW);
digitalWrite(ledpin5, LOW);
}    
else if (deger >= 250 && deger < 410)//değer bu aralıkta ise 3 adet yeşil ve sarı LED yanar. 
{
digitalWrite(ledpin1, HIGH);
digitalWrite(ledpin2, HIGH);
digitalWrite(ledpin3, HIGH);
digitalWrite(ledpin4, HIGH);
digitalWrite(ledpin5, LOW);
}
else if (deger >= 0 && deger < 250) //değer bu aralıkta ise tüm LEDler yanar. 
{
digitalWrite(ledpin1, HIGH);
digitalWrite(ledpin2, HIGH);
digitalWrite(ledpin3, HIGH);
digitalWrite(ledpin4, HIGH);
digitalWrite(ledpin5, HIGH);
}
delay(1000);        // 1sn'de bir okuma gerçekleştirilir. 
}
