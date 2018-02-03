#define enApin 9 //Enable A pin atanır. 
#define in1pin 5 //Input1 pin atanır. 
#define in2pin 6 //Input2 pin atanır. 
#define butonpin 4 //Buton pin atanır. 
int donmeyonu = 0;  //Donmeyonu ilk değer 0 atanır. 
int butonbasma = false; //butonbasma ilk değer false atanır. 

void setup() {
Serial.begin(9600); //Seri veri iletişimi başlatılır. 
pinMode(enApin, OUTPUT); //Enable A pini çıkış olarak tanımlanır. 
pinMode(in1pin, OUTPUT); //Input1 pini çıkış olarak tanımlanır. 
pinMode(in2pin, OUTPUT); //Input2 pini çıkış olarak tanımlanır. 
pinMode(buttonpin, INPUT_PULLUP); //Butonpin çıkış olarak tanımlanır. 
// DC motorun ilk dönme yönü belirleninr(motor sola doğru döner)
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
}

void loop() {
int potdeger = analogRead(A0); //  AO dan okunan değer potdeger e atanır. 
int pwmdeger = map(potValue, 0, 1023, 0 , 255); // 0-1023 arası analod deger 0-255 arası PWM değere dönüştürülür. 
Serial.println(pwmdeger); //motorun dönme hızını belirleyen değer seri port ekrana yazdırılır. 
analogWrite(enApin, pwmdeger); // pot ile belirlenen PWM sinyali(degeri) enA(enable pin)e yollanır. 
// buton değeri okunur
if (digitalRead(butonpin) == true) {  //eğer butona basılırsa
butonbasma = !butonbasma; //buton tekrar basılmamış gibi ilk değer false alır. 
}
while (digitalRead(butonpin) == true); //Buton pine true değeri geldiğinde...
delay(20); //biraz beklenir. 
// Eğer butona basılır ve donmeyonu ilk değer devam ederse...
if (butonbasma == true  & donmeyonu == 0) { 
digitalWrite(in1, HIGH); //motorun dönme yönü değiştirilir.
digitalWrite(in2, LOW);
donmeyonu = 1; //donmeyonune 1  atanır. 
delay(20); //biraz beklenir. 
}
// Eğer butona basılırsa ve donmeyonu 1 değeri alırsa...
if (pressed == false & rotDirection == 1) {
digitalWrite(in1, LOW);  //motorun dönme yönü tekrar değişir. 
digitalWrite(in2, HIGH);
donmeyonu = 0; //donmeyonu 0 atanır. 
delay(20); //biraz beklenir. 
}
}
