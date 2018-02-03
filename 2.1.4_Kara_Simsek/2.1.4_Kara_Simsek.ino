// Arduino LED pinleri tanımlanır.
int led1 = 9; 
int led2 = 8;
int led3 = 7;
int led4 = 6;
int led5 = 5;
int led6 = 4;
int led7 = 3;
int led8 = 2; 
// LEDler arası geçiş süresi 50 ms olarak ayarlanır.
const int bekleme = 50; 

void setup () 
//Arduino pinleri çıkış olarak tanımlanır. 
{
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT); 
pinMode(led6, OUTPUT); 
pinMode(led7, OUTPUT); 
pinMode(led8, OUTPUT);
} 


void loop() { 
//Sırasıyla LED1 HIGH olur, 50 ms bekler, ve söner, LED2 HIGH olur, 50 ms bekler ve //söner. Bu işlem LED 8’e kadar devam eder.
 
digitalWrite(led1,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led1,LOW); // LED söndür

digitalWrite(led2,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led2,LOW); // LED söndür
 
digitalWrite(led3,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led3,LOW); // LED söndür
 
digitalWrite(led4,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led4,LOW); // LED söndür
 
digitalWrite(led5,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led5,LOW); // LED söndür
 
digitalWrite(led6,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led6,LOW); // LED söndür
 
digitalWrite(led7,HIGH); // LED ON
delay(bekleme); 
digitalWrite(led7,LOW); // LED söndür
 
digitalWrite(led8,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led8,LOW); // LED söndür
 
//Geri dönüş:
//Sırasıyla LED8 HIGH olur, 50 ms bekler, ve söner, LED7 HIGH olur, 50 ms bekler ve 
//söner. Bu işlem LED 1’e kadar tersi yönde devam eder.

 
digitalWrite(led8,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led8,LOW); // LED söndür

digitalWrite(led7,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led7,LOW); // LED söndür
 
digitalWrite(led6,HIGH); // LED ON
delay(bekleme); 
digitalWrite(led6,LOW); // LED söndür
 
digitalWrite(led5,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led5,LOW); // LED söndür
 
digitalWrite(led4,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led4,LOW); // LED söndür
 
digitalWrite(led3,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led3,LOW); // LED söndür
 
digitalWrite(led2,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led2,LOW); // LED söndür
 
digitalWrite(led1,HIGH); // LED yak
delay(bekleme); 
digitalWrite(led1,LOW); // LED söndür

}
