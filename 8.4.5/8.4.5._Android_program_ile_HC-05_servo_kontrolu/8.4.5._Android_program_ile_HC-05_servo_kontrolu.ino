#include <SoftwareSerial.h> //kütüphaneler koda eklenir. 
#include <Servo.h>

Servo servomotor;  //servomotor isminde bir nesne tanımlanır. 
int TXpin = 3; //Tx ve Rx pinleri tanımlanır. 
int RXpin = 4;
SoftwareSerial hc06(TXpin, RXpin);  //hc06 adlı bir bluetooth nesnesi oluşturulur. 

void setup()
{
servomotor.attach(7); //servomotor 7 nolu dijital pine bağlanır. 
Serial.begin(9600);  // seri veri iletişimi başlatılır. 
hc06.begin(38400); //hc06 modül için iletişim hızı 9600 tanımlanır. 
}

void loop()
{
if(hc06.available()> 0 ) //eğer Android programdan veri girişi yapılırsa...
{
int servoaci = hc06.read();  //okunan değer servoaci isimli değişkene atanır. 
Serial.println(servoaci); //okunan değer aynı zamanda seri port ekranına yazdırılır..
servomotor.write(servoaci);  //servomotorun okunan değere gitmesi sağlanır. 
}
}
