#include <LiquidCrystal.h> //LCD kütüphanesini ekler. 

const int NTCpin = A5;  //NTC pini tanımlanır.

int deger; //NTC çıkışındaki büyüklüğü ölçmek için deger isminde bir değişken tanımlanır.
float direnc1 = 10000;  //direnc1 isminde değişkene 10000 rakamı atanır. (10K sabit direnç)
float logdirenc2, direnc2, sicaklik, santigrad; // değişkenler tanımlanır. 
float sabit1 = 1.009249522e-03, sabit2 = 2.378405444e-04, sabit3 = 2.019202697e-07; //Ölçülen direnci sıcaklığa dönüştürücek olan formülde
//kullanılacak sabitler olan sabit1, sabit2,sabit3 değişken değerleri atanır.

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    // LCD pinlerinin Arduino UNO kartına bağlanacağı pinler tanımlanır

byte derece[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() 
{ 

// derece karakteri oluşturulur
lcd.createChar(1, derece);  

// LCD'inin sütun ve satır sayısı belirtilerek başlatılır. 
lcd.begin(16, 2); 
//Sıcaklık değeri mesajı ekrana yazdırılır. 
lcd.print("Sicaklik degeri:"); 
} 

void loop() 
{ 
deger = analogRead(NTCpin);  //NTC çıkışından okunan analog sayı, deger isimli değişkene atanır.
 
direnc2 = direnc1 * (1023.0 / (float)deger - 1.0); //direnc2 değişkenine atanacak hesaplama yapılır. 
logdirenc2 = log(direnc2); //direnc2 isimli değişkenin logaritması alınarak logdirenc2 isimli değişkene atanır. 
sicaklik = (1.0 / (sabit1 + sabit2*logdirenc2 + sabit3*logdirenc2*logdirenc2*logdirenc2)); // kelvin cinsinden sıcaklık değeri hesaplanır.
santigrad = sicaklik - 273.15;//hesaplanan kelvin değeri santigrad değerine dönüştürülür.
  
// imleç (0,1)/2. satırdan başlatılır. 
lcd.setCursor(0, 1); 
// ölçülen sıcaklık değeri 2.satırda yazar. 
lcd.print(santigrad); 
lcd.print(" C");
lcd.setCursor(7, 1);
lcd.write((byte)1);
delay(500); //Her yarım saniyede değer okunur. 
}
