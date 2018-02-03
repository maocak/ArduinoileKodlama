int buton_sag=2; //buton pin numaraları atanır. 
int buton_sol=3;

int motor_pin1= 8; //motor pin numaraları atanır. 
int motor_pin2=9;
int motor_pin3=10;
int motor_pin4=11;

int motor_hiz=2; //motor hızı atanır. 

int deger1=0; //deger1 ve deger2 değişkeni ilk değerleri 0 atanır. 
int deger2=0;

void setup() {
// buton pinleri giriş olarak atanır. 
pinMode(buton_sag,INPUT);
pinMode(buton_sol,INPUT);
//motor pinleri çıkış olarak atanır. 
pinMode(motor_pin1,OUTPUT);
pinMode(motor_pin2, OUTPUT);
pinMode(motor_pin3, OUTPUT);
pinMode(motor_pin4, OUTPUT);

}

void loop() {

deger1=digitalRead(buton_sag); //eğer sağdaki butona basılıp HIGH değeri alınınca...
if (deger1==HIGH)
{ //4 aşamalı şekilde tez fazlı olarak adım motor sürülmeye başlar. 1000,0100,0010,0001 (1.pinden 4. pine doğru)
digitalWrite(motor_pin1, HIGH); // 1-0-0-0
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin4, LOW);
delay(motor_hiz);
  
digitalWrite(motor_pin1, LOW); //0-1-0-0
digitalWrite(motor_pin2, HIGH);
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin4, LOW);
delay(motor_hiz);
  
digitalWrite(motor_pin1, LOW); //0-0-1-0
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin3, HIGH);
digitalWrite(motor_pin4, LOW);
delay(motor_hiz);
  
digitalWrite(motor_pin1, LOW); //0-0-0-1
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin4, HIGH);
delay(motor_hiz);
  
} 
deger2=digitalRead(buton_sol); //eğer soldaki butona basılıp HIGH değeri elde edilirse...
if(deger2==HIGH)
{ //adım motor tek fazlı olarak TERS yönde sürülmeye başlar. (4. pinden, 1. pine doğru)
digitalWrite(motor_pin4, HIGH); // 1-0-0-0
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin1, LOW);
delay(motor_hiz);

digitalWrite(motor_pin4, LOW); //0-1-0-0
digitalWrite(motor_pin3, HIGH);
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin1, LOW);
delay(motor_hiz);

digitalWrite(motor_pin4, LOW);  //0-0-1-0
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin2, HIGH);
digitalWrite(motor_pin1, LOW);
delay(motor_hiz);

digitalWrite(motor_pin4, LOW);  //0-0-0-1
digitalWrite(motor_pin3, LOW);
digitalWrite(motor_pin2, LOW);
digitalWrite(motor_pin1, HIGH);
delay(motor_hiz);
}
}
