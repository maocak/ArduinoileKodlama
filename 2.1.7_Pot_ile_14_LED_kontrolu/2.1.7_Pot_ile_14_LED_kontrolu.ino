//0-13 arası tüm dijital pinler LED çıkışları olarak tanımlanır.
int ledpin1 = 13;
int ledpin2 = 12;
int ledpin3 = 11;
int ledpin4 = 10;
int ledpin5 = 9;
int ledpin6 = 8;
int ledpin7 = 7;
int ledpin8 = 6;
int ledpin9 = 5;
int ledpin10 = 4;
int ledpin11 = 3;
int ledpin12 = 2;
int ledpin13 = 1;
int ledpin14 = 0;
//Analog A0 pini potansiyometre çıkışı olarak tanımlanır.
int potpin = A0;
//potdeger isminde bir değişkene ilk başlangıç değeri olan 0 atanır.
int potdeger = 0;

void setup(){
//Ardiuno pinleri(0-13) çıkış olarak tanımlanır. 
pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);
pinMode(ledpin3,OUTPUT);
pinMode(ledpin4,OUTPUT);
pinMode(ledpin5,OUTPUT);
pinMode(ledpin6,OUTPUT);
pinMode(ledpin7,OUTPUT);
pinMode(ledpin8,OUTPUT);
pinMode(ledpin9,OUTPUT);
pinMode(ledpin10,OUTPUT);
pinMode(ledpin11,OUTPUT);
pinMode(ledpin12,OUTPUT);
pinMode(ledpin13,OUTPUT);
pinMode(ledpin14,OUTPUT);
// analog değerleri okuyacağımız Analog pin GİRİŞ olarak tanımlanır.
pinMode(potpin,INPUT);
}

void loop(){
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin); 

//eğer bu değer 0 ile 74 arası sayısal bir değerse LED1 yanar, değilse söner. 
if(potdeger>=0 && potdeger<74)
{ 
digitalWrite(ledpin1,HIGH);
}
else{
digitalWrite(ledpin1,LOW);
}

//Analog girişten alınan değer potdeger değişkenine aktarılır. Her koşul sonlandığında bu //değerin tekrar potdeger değişkenine atanması gerekir.   Çünkü bir sonraki koşulda potdeger //değişkeninin alacağı yeni değere göre işlem gerçekleştirilecektir.    

potdeger = analogRead(potpin);
//eğer bu değer 74 ile 148 arası sayısal bir değerse LED2 yanar, değilse söner. 
if(potdeger>=74 && potdeger<148)
{ 
digitalWrite(ledpin2,HIGH);
}
else{
digitalWrite(ledpin2,LOW);
}
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 148 ile 222 arası sayısal bir değerse LED3 yanar, değilse söner. 
if(potdeger>=148 && potdeger<222)
{ 
digitalWrite(ledpin3,HIGH);
}
else{
digitalWrite(ledpin3,LOW);
}
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 222 ile 296 arası sayısal bir değerse LED4 yanar, değilse söner. 
if(potdeger>=222 && potdeger<296)
{ 
digitalWrite(ledpin4,HIGH);
}
else{
digitalWrite(ledpin4,LOW);
}
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 296 ile 370 arası sayısal bir değerse LED5 yanar, değilse söner. 
if(potdeger>=296 && potdeger<370)
{ 
digitalWrite(ledpin5,HIGH);
}
else{
digitalWrite(ledpin5,LOW);
}
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 370 ile 444 arası sayısal bir değerse LED6 yanar, değilse söner. 
if(potdeger>=370 && potdeger<444)
{ 
digitalWrite(ledpin6,HIGH);
}
else{
digitalWrite(ledpin6,LOW);
}

//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 444 ile 518 arası sayısal bir değerse LED7 yanar, değilse söner. 
if(potdeger>=444 && potdeger<518)
{ 
digitalWrite(ledpin7,HIGH);
}
else{
digitalWrite(ledpin7,LOW);
}
 
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 518 ile 592 arası sayısal bir değerse LED8 yanar, değilse söner. 
if(potdeger>=518 && potdeger<592)
{ 
digitalWrite(ledpin8,HIGH);
}
else{
digitalWrite(ledpin8,LOW);
}

//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 592 ile 666 arası sayısal bir değerse LED9 yanar, değilse söner. 
if(potdeger>=592 && potdeger<666)
{ 
digitalWrite(ledpin9,HIGH);
}
else{
digitalWrite(ledpin9,LOW);
}


//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 666 ile 740 arası sayısal bir değerse LED10 yanar, değilse söner. 
if(potdeger>=666 && potdeger<740)
{ 
digitalWrite(ledpin10,HIGH);
}
else{
digitalWrite(ledpin10,LOW);
}
//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 740 ile 814 arası sayısal bir değerse LED11 yanar, değilse söner. 
if(potdeger>=740 && potdeger<814)
{ 
digitalWrite(ledpin11,HIGH);
}
else{
digitalWrite(ledpin11,LOW);
}

//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 814 ile 888 arası sayısal bir değerse LED12 yanar, değilse söner. 
if(potdeger>=814 && potdeger<888)
{ 
digitalWrite(ledpin12,HIGH);
}
else{
digitalWrite(ledpin12,LOW);
}

//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 888 ile 972 arası sayısal bir değerse LED13 yanar, değilse söner. 
if(potdeger>=888 && potdeger<972)
{ 
digitalWrite(ledpin13,HIGH);
}
else{
digitalWrite(ledpin13,LOW);
}

//Analog girişten okunan değer potdeger değişkenine aktarılır.
potdeger = analogRead(potpin);
//eğer bu değer 972 ile 1024 arası sayısal bir değerse LED14 yanar, değilse söner. 
if(potdeger>=972 && potdeger<1024)
{ 
 digitalWrite(ledpin14,HIGH);
}
else{
digitalWrite(ledpin14,LOW);
}
}

