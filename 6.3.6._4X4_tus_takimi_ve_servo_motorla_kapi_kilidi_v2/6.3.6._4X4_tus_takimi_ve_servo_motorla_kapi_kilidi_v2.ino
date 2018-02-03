#include <Keypad.h> //tuş takımı ve servo motorun çalışması için kütüphaneler dahil edilir. 
#include <Servo.h>

Servo servomotor; //servo motor nesnesi oluşturulur. 
char* sifre = "4567"; //4 karakterli bir şifre belirlenir. 
int durum = 0; //durum adlı değişkene ilk değeri 0 olarak atanır. 

const byte satirlar = 4;  //tuş takımının satır ve sütun sayısı belirlenir.
const byte sutunlar = 4; 
//tuş takımı üzerindeki düğmeler karakter olarak tanımlanır. 
char dugmeler[satirlar][sutunlar] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};



byte satirpinleri[satirlar] = { 9, 8, 7, 6 }; //tuş takımındaki uçların Arduino UNOya bağlanacak pinleri tanımlanır.  
byte sutunpinleri[sutunlar] = { 5, 4, 3, 2 };

Keypad tustakimi = Keypad( makeKeymap(dugmeler), satirpinleri, sutunpinleri, satirlar, sutunlar ); //tuş takımı nesnesi oluşturulur. 

int kirmiziLEDpin = 12; //kırmızı ve yeşil LEDlerin bağlanacağı pin numaraları int olarak atanır. 
int yesilLEDpin = 10;

void setup()
{
Serial.begin(9600);
pinMode(kirmiziLEDpin, OUTPUT);//kırmızı ve yeşil LED pinleri çıkış olarak tanımlanır. 
pinMode(yesilLEDpin, OUTPUT);

servomotor.attach(11); // servo motor 11 nolu dijital pine bağlanır. 
kilitdurumu(0);  //fonksiyona ilk değer olarak 0 yollanır. Böylece program başladığında kırmızı LED yanık ve servo kilit kapalı pozisyonuna gelir. 
}

void loop()
{
char dugme = tustakimi.getKey();  //tuş takımından girilen karakterler getKey yardımıyla çekilir. 
if (dugme == '*' || dugme == '#')  //eğer * ya da # düğmelerine basılırsa...  
{
durum = 0;
kilitdurumu(0); //fonksiyona 0 değeri yolllanır ve kırmızı LED yanar ve servo kilit kapalı durumuna gelir.
}

if (dugme == sifre[durum]) //şifre kontrolu dizi yardımıyla yapılır. 
{
durum ++;
}
if (durum == 4) //eğer girilen 4 elemanlı diziye atanan şifreye eşitse bu durumda...
{
kilitdurumu(1);  //fonksiyona 1 değeri yollanır. Yeşil LED yanar ve servo motor kilit açık konumuna gelir. 
}
delay(100);
}

void kilitdurumu(int kilitac)
{
if (kilitac==0)  //0(false) durumunda kırmızı LED yanar. Servo motor 0 açısına gider(kilit kapalı)
{
digitalWrite(kirmiziLEDpin, HIGH);
digitalWrite(yesilLEDpin, LOW);
servomotor.write(0);
Serial.println("Kapı kilitli");
}

else if(kilitac==1)  //1(true) durumunda yeşil LED yanar. Servo motor 90 açısına gider(kilit açık)
{
digitalWrite(kirmiziLEDpin, LOW);
digitalWrite(yesilLEDpin, HIGH);
servomotor.write(90);
Serial.println("Kapı açık");
}
}

