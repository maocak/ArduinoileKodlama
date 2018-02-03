#include <Wire.h>
 
void setup()
{
Wire.begin();
Serial.begin(9600);
while (!Serial);             
Serial.println("\nI2C tarama");
}
     
void loop()
{
byte hata, adres;
int cihaz;
Serial.println("Taranıyor...");
     
cihaz = 0;
for(adres = 1; adres < 127; adres++ )
{
Wire.beginTransmission(adres);
hata = Wire.endTransmission();
if (hata == 0)
{
Serial.print("I2C cihaz şu adresde bulundu: 0x");
if (adres<16)
Serial.print("0");
Serial.print(adres,HEX);
Serial.println("  !");
cihaz++;
}
else if (hata==4)
{
Serial.print("Şu adreste bilinmeyen bir hata oluştu: 0x");
if (adres<16)
Serial.print("0");
Serial.println(adres,HEX);
}    
}
if (cihaz == 0)
Serial.println("Herhangi bir I2C cihaz yok\n");
else
Serial.println("bitti\n");
delay(5000);          
}

