#include <SoftwareSerial.h>  
SoftwareSerial BTserial(2, 3); // TX ve RX pin uçları bağlanır. 
 
void setup() 
{
Serial.begin(9600);
Serial.println("AT komutlarını girin:");
 
BTserial.begin(38400);  // HC-05 varsayılan seri hızı 38400'tür
}
 
void loop()
{
// HC-05'ten okumaya devam eder ve Arduino Seri port ekranına gönderir.
if (BTserial.available())
{  
Serial.write(BTserial.read());
}
// Arduino Seri port ekranından okumaya devam eder ve HC-05'e gönderir.
if (Serial.available())
{
BTserial.write(Serial.read());
}
}
