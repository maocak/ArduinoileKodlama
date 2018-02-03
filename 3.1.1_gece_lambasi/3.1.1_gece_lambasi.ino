int ldrpin = A5; //A5 nolu analog pin LDR pin olarak tanımlanır. 
unsigned int ldrdeger = 0;

void setup() {
pinMode (7, OUTPUT);//7 nolu digital pin LED pini olarak tanımlanır. 
Serial.begin(9600); //seri veri girişi başlatılır. 
}

void loop() {
ldrdeger = analogRead(ldrpin); //LDR'de okunan değer ldrdeger isimli değişkene atanır. 
if(ldrdeger<500) digitalWrite(7, HIGH); //eğer okunan analog değer 840 dan büyükse LED yanar. 
else digitalWrite(7, LOW); //değilse LED sönüktür. 
Serial.println(ldrdeger); //LDR'ye düşen ışık miktarı değişdikçe okunan analog değer seri port ekranına yazdırılır.
}
