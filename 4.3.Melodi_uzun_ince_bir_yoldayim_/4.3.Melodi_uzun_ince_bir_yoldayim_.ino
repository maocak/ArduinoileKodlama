#define  Do     2093 //1 oktavlık notaların frekans değerleri atanır. 
#define  Re     2349 
#define  Mi     2637
#define  Fa     2794
#define  Sol    3136
#define  La     3520
#define  Si     3951

int buzzerpin = 3; //buzzer pini tanımlanır
int notasayisi1 =11; //1. dizi için kullanılacak nota sayısı tanımlanır.
int notasayisi2 =13; //2. dizi için kullanılacak nota sayısı tanımlanır.  
int notasayisi3 = 22; //3.dizi için kullanılacak nota sayısı tanımlanır. 
int notasayisi4 = 20; //4.dizi için kullanılacak nota sayısı tanımlanır. 
  
int dizi1[] = {Fa,Sol,Sol,Fa, Mi, Re, Fa, Mi, Re, Re,Re}; //1.dizideki notalar
int dizi2[]= {La, Sol, La, Fa, Sol, Fa, Mi, Re, Fa, Mi, Re, Re,Re}; //2.dizideki notalar
int dizi3[]= {Si, Do, Do, Do, Do, Si, La, Do, Si, Si, Si, La, Sol, Si, La, La, La, Sol, Fa, La, Sol,Sol};  //3.dizideki notalar
int dizi4[]= {Sol, Fa, Mi, Sol, Fa, Fa, Fa, Fa, Mi, Re, Fa, Mi, Mi, Mi, Re, Do, Mi, Re, Re, Re};  //4.dizideki notalar
            
void setup()
{
Serial.begin(9600);  //Seri veri girişi başlatılır. 
}

void loop()
{
for (int i = 0; i < notasayisi1; i++) //1. dizide bulunan 10 notanın sırasıyla çalması için döngü kullanılır. 
{
tone(buzzerpin, dizi1[i]); // 1. dizide bulunan notalar sırasıyla çalmaya başlar 
Serial.println(dizi1[i]);  //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(310); //Her nota arasında 310 msn bekleme süresi vardır. 
}
noTone(buzzerpin); //Baştan sonra notalar çalması durdurulur.
delay(750); //1sn beklenir.

for (int i = 0; i <= notasayisi2; i++)//2. dizide bulunan 12 notanın sırasıyla çalması için döngü kullanılır. 
{
tone(buzzerpin, dizi2[i]); //2. dizide bulunan notalar sırasıyla çalmaya başlar 
Serial.println(dizi2[i]); //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(300); //Her nota arasında 300 msn bekleme süresi vardır. 
}      
noTone(buzzerpin); //Sondan başa notaların çalması durdurulur. 
delay(1000);// 1 sn beklenir. 

for (int i = 0; i <= notasayisi3; i++)//3. dizide bulunan 22 notanın sırasıyla çalması için döngü kullanılır. 
{
tone(buzzerpin, dizi3[i]); //3. dizide bulunan notalar çalmaya başlar.
Serial.println(dizi3[i]); //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(300); //Her nota arasında300 msn bekleme süresi vardır. 
}      
noTone(buzzerpin); //Notaların çalması durdurulur. 

for (int i = 0; i <= notasayisi4; i++)//4. dizide bulunan 20 notanın sırasıyla çalması için döngü kullanılır. 
{
tone(buzzerpin, dizi4[i]); //4. dizide bulunan notalar çalmaya başlar. 
Serial.println(dizi4[i]); //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(300); //Her nota arasında 300 msn bekleme süresi vardır. 
}      
noTone(buzzerpin); //Notaların çalması durdurulur. 
delay(1000);// 1 sn beklenir. 

}
