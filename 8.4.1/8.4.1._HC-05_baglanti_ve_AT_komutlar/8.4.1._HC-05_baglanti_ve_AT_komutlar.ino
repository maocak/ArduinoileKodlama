#include <SoftwareSerial.h>
SoftwareSerial BTserial(8, 9); // // TX ve RX pin uçları bağlanır. 

void setup() {
Serial.begin(9600); //seri port iletişim hızı
Serial.println("AT komutlarını girin:");
BTserial.begin(38400); // HC-05 varsayılan seri hızı 38400'dir
}
void loop()
{
if (BTserial.available()) // HC-05'dan okumaya devam eder ve Arduino Seri port ekranına gönderir.
Serial.write(BTserial.read());
if (Serial.available())  // Arduino Seri port ekranından okumaya devam eder ve HC-06'ya gönderir.
BTserial.write(Serial.read());
}
