#include<Servo.h> //servo motor kütüphanesi çağrılır. 

int ntcpin = 0; //NTC pini tanımlanır.
int deger; //NTC çıkışındaki büyüklüğü ölçmek için deger isminde bir değişken tanımlanır.
float direnc1 = 10000;  //direnc1 isminde değişkene 10000 rakamı atanır. (10K sabit direnç)
float logdirenc2, direnc2, sicaklik, santigrad; //  float tipinde değişkenler tanımlanır. 
float sabit1 = 1.009249522e-03, sabit2 = 2.378405444e-04, sabit3 = 2.019202697e-07; //Ölçülen direnci sıcaklığa dönüştürecek olan formülde kullanılacak sabitler olan 
//sabit1, sabit2,sabit3 değişken değerleri atanır.

Servo servomotor; //servo motor nesnesi oluşturulur. 
 
void setup(void)
{
servomotor.attach(3);  //servo motor 3 nolu dijital pine bağlanır. 
Serial.begin(9600); //seri veri iletişimi başlatılır. 
}
 
void loop(void) {
deger = analogRead(ntcpin); //NTC çıkışından okunan analog sayı deger isimli değişkene //atanır. 
  
direnc2 = direnc1 * (1023.0 / (float)deger - 1.0); //direnc2 değişkenine atanacak hesaplama //yapılır. 
logdirenc2 = log(direnc2); //direnc2 isimli değişkenin logaritması alınarak logdirenc2 isimli //değişkene atanır. 
sicaklik = (1.0 / (sabit1 + sabit2*logdirenc2 + sabit3*logdirenc2*logdirenc2*logdirenc2)); // //kelvin cinsinden sıcaklık değeri hesaplanır.
santigrad = sicaklik - 273.15;//hesaplanan kelvin değeri santigrad değerine dönüştürülür.
Serial.print("Ölçülen sıcaklık değeri: ");  //okunan değer seri port ekranına yazdırılır. 
Serial.print(santigrad);
Serial.println(" C");   

delay(1000); //her 1 saniyede bir sıcaklık ölçülür. 
int sicaklik;
  
sicaklik = map(santigrad,0,50,0,180); //0-50 arası ölçülen sıcaklık değeri 0-180 arası açı derecesine döndürülür. 
  
servomotor.write(sicaklik);
delay(100);
}
