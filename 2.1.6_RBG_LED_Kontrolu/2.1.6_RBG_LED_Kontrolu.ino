// Arduino ile RGB LED Kontrolü 

int KirmiziLed=5;
int YesilLed=6;
int MaviLed=9;

// 5,6 ve 9 nolu pinlere sırasıyla kırmızı, yeşil ve mavi LED çıkışları tanımlanır.
void setup()
// arduino pinleri çıkış olarak tanımlanır.
{
pinMode(KirmiziLed,OUTPUT);
pinMode(YesilLed,OUTPUT);
pinMode(MaviLed,OUTPUT);

}

void loop()
// Deneyde kullanılan RGB LED'i ortak anodlu olduğu için LED'ler LOW durumunda yanar
{
//İlk önce LED kırmızı  yanar.  
digitalWrite(MaviLed,HIGH);  
digitalWrite(YesilLed,HIGH);  
digitalWrite(KirmiziLed,LOW);  
delay(1500);
//LED yeşil  yanar.  
digitalWrite(MaviLed,HIGH);
digitalWrite(YesilLed,LOW);  
digitalWrite(KirmiziLed,HIGH); 
delay(1500);
//LED mavi yanar.  
digitalWrite(MaviLed,LOW);  
digitalWrite(YesilLed,HIGH);  
digitalWrite(KirmiziLed,HIGH);  
delay(1500);
//LED beyaz yanar.Kırmızı, yeşil ve mavi hepsi birden yandığından ışık rengi beyaz görünür.
digitalWrite(MaviLed,LOW);  
digitalWrite(YesilLed,LOW);  
digitalWrite(KirmiziLed,LOW); 
delay(1500);
//LED söner. RGB ortak anotlu olduğu için pin uçlarına akım geçmez.
digitalWrite(MaviLed,HIGH);  
digitalWrite(YesilLed,HIGH);  
digitalWrite(KirmiziLed,HIGH); 
delay(1500);
}

