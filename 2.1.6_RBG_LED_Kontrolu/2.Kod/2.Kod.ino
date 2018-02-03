int kirmiziPin =5;//5,6 ve 9 nolu pinler kırmızı, yeşil ve mavi LED çıkışları olarak tanımlanır. 
int yesilPin= 6;
int maviPin =9;

void setup() {
//Arduino pinleri çıkış olarak tanımlanır.
pinMode (kirmiziPin, OUTPUT);
pinMode (yesilPin, OUTPUT);
pinMode (maviPin, OUTPUT);
}

void loop() {
// renkatama isminde tanımlanan bir fonksiyona 3 farklı sayı içeren değerler yollanır. 0 ile 255 
//olması gereken bu sayılar sırasıyla kırmızı, yeşil ve mavi LEDleri kontrol eder. 
//Örneğin renkatama(255,0,0) kırmızı LEDi yakar. 
  
renkatama (255,0,0);//kırmızı LED yanar. 1.5 saniye bekler.
delay(1500);
renkatama(0,255,0);//yeşil LED yanar. 1,5 saniye bekler. 
delay(1500);
renkatama(0,0,255);//mavi LED yanar. 1,5 saniye bekler. 
delay(1500);
renkatama(255,255,0);//kırmızı=255, yeşil=255, sarı renk elde edilir.
delay(1500);
renkatama(80,0,80);//kırmızı=80, yeşil=0, mavi=80. Mor elde edilir. 
delay(1500);
renkatama(0,255,255);// kırmızı=0, yeşil=255, mavi=255. Su rengi elde edilir. 
delay(1500);

}
//renk atama foksiyonu her defasında loop() dan aldığı değerle analogWrite() komutu ile 
//ilgili LED çıkışlarına göndererek istenen renklerin elde edilmesini sağlar. 
void renkatama (int kirmizi, int yesil, int mavi)
//ortak anot RGB kullanıldığından LED çıkışlarında elde edilen değerler tersine çevrilmelidir. 
//bundan dolayı değerler en yüksek değer olan 255’ten çıkarılmalıdır. eğer ortak katot rgb 
//kullanılıyorsa maviyle yazılan koda gerek yoktur. 
{
kirmizi=255-kirmizi;
yesil=255-yesil;
mavi=255-mavi;
//Çıkışlara yollanan değerler yardımıyla kırmızı, yeşil, ve mavi LEDler kontrol edilir.  
analogWrite(kirmiziPin, kirmizi);
analogWrite(yesilPin, yesil);
analogWrite(maviPin, mavi);
}

