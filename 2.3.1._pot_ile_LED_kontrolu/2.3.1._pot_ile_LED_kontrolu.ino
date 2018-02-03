int ledpin = 6; //6 nolu pin led pini olarak tanımlanır.
int potpin = 0; //A0 pini pot pini olarak tanımlanır. 
     
void setup()  {
Serial.begin(4800); // seri portu açar, veri hızını 9600 bps e ayarlar. 
pinMode(ledpin, OUTPUT); //led pini çıkış olarak tanımlanır. 
}
     
void loop()  {
potpin = (analogRead(0)/4); // pot dan gelen 0-1023 analog değerleri PWM aralığı olan 0-255 aralığına çevirmek için 1023/4=255 bölme yapılır. 
Serial.print("Potdan okunan analog değer=" ); //seri port ekranına yazı yazdırılır. 
Serial.println(potpin); //pot çıkışından okunan her değer seri port ekranına yazdırılır. 
analogWrite(ledpin, potpin);  //potdan okunan 0-255 arası değere göre ledpin kontrol edilerek LEDin parlaklığı değişir 
delay(10);  // 10 msn beklenir.                           
}


