int ntcpin = 5; //NTC pini tanımlanır.
int deger; //NTC çıkışındaki büyüklüğü ölçmek için deger isminde bir değişken tanımlanır.
float direnc1 = 10000;  //direnc1 isminde değişkene 10000 rakamı atanır. (10K sabit direnç)
float logdirenc2, direnc2, sicaklik, santigrad; // değişkenler tanımlanır. 
float sabit1 = 1.009249522e-03, sabit2 = 2.378405444e-04, sabit3 = 2.019202697e-07; //Ölçülen direnci sıcaklığa dönüştürücek olan formülde
//kullanılacak sabitler olan sabit1, sabit2,sabit3 değişken değerleri atanır.

void setup() {
Serial.begin(9600); //seri veri iletişim başlatılır. 
}

void loop() {
deger = analogRead(ntcpin); //NTC çıkışından okunan analog sayı deger isimli değişkene atanır. 
direnc2 = direnc1 * (1023.0 / (float)deger - 1.0); //direnc2 değişkenine atanacak hesaplama yapılır. 
logdirenc2 = log(direnc2); //direnc2 isimli değişkenin logaritması alınarak logdirenc2 isimli değişkene atanır. 
sicaklik = (1.0 / (sabit1 + sabit2*logdirenc2 + sabit3*logdirenc2*logdirenc2*logdirenc2)); // kelvin cinsinden sıcaklık değeri hesaplanır.
santigrad = sicaklik - 273.15;//hesaplanan kelvin değeri santigrad değerine dönüştürülür.
Serial.print("Ölçülen sıcaklık değeri: ");  //okunan değer seri port ekranına yazdırılır. 
Serial.print(santigrad);
Serial.println(" C");   
delay(500);
}
