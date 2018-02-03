#include <SoftwareSerial.h>  
SoftwareSerial BTserial(2, 3); // TX ve RX pin uçları bağlanır. 
 
void setup() 
{
Serial.begin(9600);
Serial.println("AT komutlarını girin:");
 
BTserial.begin(38400);  // HC-06 varsayılan seri hızı 9600'dir
}
 
void loop()
{
// HC-06'dan okumaya devam eder ve Arduino Seri port ekranına gönderir.
if (BTserial.available())
{  
Serial.write(BTserial.read());
}
// Arduino Seri port ekranından okumaya devam eder ve HC-06'ya gönderir.
if (Serial.available())
{
BTserial.write(Serial.read());
}
}
