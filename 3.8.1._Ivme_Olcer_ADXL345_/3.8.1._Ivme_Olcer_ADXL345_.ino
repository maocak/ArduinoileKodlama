#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
// ADXL345 sensörüne bir kimlik numarası atanır(12345) 
Adafruit_ADXL345_Unified ivmeolcer = Adafruit_ADXL345_Unified(12345);

void sensorbilgileri(void) //sensörle ilgili teknik bilgiler ekrana yazdırılır.
{
sensor_t sensorbilgi; //sensör hakkında bilgileri vermek için kullanılan ve Adafruit_Sensor kütüphanesinde yer alan bir komuttur. 
ivmeolcer.getSensor(&sensorbilgi);//sensorle ilgili bilgiler okunur. 
Serial.println("------------------------------------");
Serial.print  ("Sensor:       "); Serial.println(sensorbilgi.name);
Serial.print  ("Surucu versiyonu:   "); Serial.println(sensorbilgi.version);
Serial.print  ("Kimlik numarasi:    "); Serial.println(sensorbilgi.sensor_id);
Serial.print  ("En buyuk deger:    "); Serial.print(sensorbilgi.max_value); Serial.println(" m/s^2");
Serial.print  ("En kucuk deger:    "); Serial.print(sensorbilgi.min_value); Serial.println(" m/s^2");
Serial.print  ("Hassasiyet   "); Serial.print(sensorbilgi.resolution); Serial.println(" m/s^2");  
Serial.println("------------------------------------");
Serial.println("");
delay(500);
}

void veriokumaaraligi(void)
{
Serial.print  ("Veri okuma araligi:    ");  //Hangi Hz'de veri okunduğu ekrana yazdırılır
  
switch(ivmeolcer.getDataRate())
{
case ADXL345_DATARATE_3200_HZ:
Serial.print  ("3200 "); 
break;
case ADXL345_DATARATE_1600_HZ:
Serial.print  ("1600 "); 
break;
case ADXL345_DATARATE_800_HZ:
Serial.print  ("800 "); 
break;
case ADXL345_DATARATE_400_HZ:
Serial.print  ("400 "); 
break;
case ADXL345_DATARATE_200_HZ:
Serial.print  ("200 "); 
break;
case ADXL345_DATARATE_100_HZ:
Serial.print  ("100 "); 
break;
case ADXL345_DATARATE_50_HZ:
Serial.print  ("50 "); 
break;
case ADXL345_DATARATE_25_HZ:
Serial.print  ("25 "); 
break;
case ADXL345_DATARATE_12_5_HZ:
Serial.print  ("12.5 "); 
break;
case ADXL345_DATARATE_6_25HZ:
Serial.print  ("6.25 "); 
break;
case ADXL345_DATARATE_3_13_HZ:
Serial.print  ("3.13 "); 
break;
case ADXL345_DATARATE_1_56_HZ:
Serial.print  ("1.56 "); 
break;
case ADXL345_DATARATE_0_78_HZ:
Serial.print  ("0.78 "); 
break;
case ADXL345_DATARATE_0_39_HZ:
Serial.print  ("0.39 "); 
break;
case ADXL345_DATARATE_0_20_HZ:
Serial.print  ("0.20 "); 
break;
case ADXL345_DATARATE_0_10_HZ:
Serial.print  ("0.10 "); 
break;
default:
Serial.print  ("???? "); 
break;
}  
Serial.println(" Hz");  
}

void verihassasiyet(void)
{
Serial.print  ("Aralik:         +/- "); //hangi hassasiyette veri okunduğu ekrana yazdırılır. 
  
switch(ivmeolcer.getRange())
{
case ADXL345_RANGE_16_G:
Serial.print  ("16 "); 
break;
case ADXL345_RANGE_8_G:
Serial.print  ("8 "); 
break;
case ADXL345_RANGE_4_G:
Serial.print  ("4 "); 
break;
case ADXL345_RANGE_2_G:
Serial.print  ("2 "); 
break;
default:
Serial.print  ("?? "); 
break;
}  
Serial.println(" g");  
}

void setup(void) 
{
Serial.begin(9600);//seri veri alışverişi başlatılır. 
Serial.println("Ivme olcer test"); Serial.println("");
  
//sensör başlatılır
if(!ivmeolcer.begin())
{
//eğer sensör bağlantıları yanlışsa bu uyarıyı verir. 
Serial.println("ADXL345 bulunamadi ... luften baglantinizi kontrol ediniz!");
while(1);
}

//uygulama için hangi hassasiyet aralığı seçileceği tanımlanır. Bu uygulamada 16g kullanılmıştır.istenirse 2,4,8 g de aktif hale getirilebilir.
ivmeolcer.setRange(ADXL345_RANGE_16_G);
// ivmeolcer.SetRange(ADXL345_RANGE_8_G);
// ivmeolcer.SetRange(ADXL345_RANGE_4_G);
// ivmeolcer.SetRange(ADXL345_RANGE_2_G);
  
//Yukarda tanımlanan sensorbilgileri isimli fonksiyon çağrılarak sensörün teknik özellikleri ekrana yazdırılır.Bu 1 defaya mahsustur. 
sensorbilgileri();
  
//veriokumaraligi ve verihassasiyet fonksiyonları çağrılarak seri port ekranına bu değerler yazdırılır. Bu bilgiler 1 defa yazdırılır.
veriokumaaraligi();
verihassasiyet();
Serial.println("");
}

void loop(void) 
{

sensors_event_t olay; //Belirlenen bir anda sensörden veri çekmek için kullanılan ve Adafruit_Sensor kütüphanesinde yer alan bir komuttur. 
ivmeolcer.getEvent(&olay); //sensörden veri okunur. 
 
// sensörden okunan xyz koordinat değerleri seri port ekranına yazdırılır. Sonuç m/s^2 cinsindendir.
Serial.print("X: "); Serial.print(olay.acceleration.x); Serial.print("  ");
Serial.print("Y: "); Serial.print(olay.acceleration.y); Serial.print("  ");
Serial.print("Z: "); Serial.print(olay.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
delay(500); //Bir sonraki koordinat okuması için 0.5 saniye belirlenir. 
}
