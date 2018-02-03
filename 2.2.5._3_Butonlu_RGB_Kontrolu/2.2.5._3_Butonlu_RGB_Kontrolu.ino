// Kırmızı, Yeşil ve Mavi led pinleri tanımlanır
int kirmizipin = 9;
int yesilpin = 10;
int mavipin = 11;
//Kırmızı, Yeşil ve Mavi renk tonlarını ayarlamak için kullanılacak butonların bağlanacağı pinler tanımlanır
int kirmizibuton = 2;
int yesilbuton = 3;
int mavibuton = 4;
//RGB LEDin başlangıçta sönük olması için ön değerler atanır
int kirmizi= 0;
int mavi= 0;
int yesil = 0;

void setup() {
//Kırmızı, Yeşil ve Mavi pinler çıkış olarak tanımlanır
pinMode(kirmizipin, OUTPUT);
pinMode(yesilpin,OUTPUT);
pinMode(mavipin, OUTPUT);
//Kırmızı, Yeşil ve Mavi renk tonlarını kontrol edecek butonlar dahili pullup direnci kullanılarak giriş olarak tanımlanır
pinMode(kirmizibuton, INPUT_PULLUP);
pinMode(yesilbuton, INPUT_PULLUP);
pinMode(mavibuton, INPUT_PULLUP);
}

void loop() {
// Eğer kırmızı rengi kontrol edecek butona basılırsa 0 ile 255 arasında giderek artan değer üretilerek kirmizi değişkenine atanır  
if(digitalRead(kirmizibuton)== LOW)
{
kirmizi++;
if(kirmizi==255){
kirmizi= 0;
}
}
// Eğer yeşil rengi kontrol edecek butona basılırsa 0 ile 255 arasında giderek artan değer üretilerek yesil değişkenine atanır 
if (digitalRead(yesilbuton)== LOW)
{
yesil++;
if(yesil==255){
yesil=0;
}
}
// Eğer mavi rengi kontrol edecek butona basılırsa 0 ile 255 arasında giderek artan değer üretilerek mavi değişkenine atanır 
if(digitalRead(mavibuton)== LOW)
{
mavi++;
if(mavi==255)
{
mavi=0;
}
}
//Elde edilen kırmızı, yeşil ve mavi değerleri renkatama fonksiyonuna yollanır. 
renkatama(kirmizi,yesil,mavi);
delay(15); //her butona basıldığında 15 ms bekler.
}
//renkatama isimli bir fonksiyon tanımlanarak, her butona basıldığında artan renk değerleri analogWrite ile ilgili LED pinine yollanır.
void renkatama(int kirmizi, int yesil, int mavi)
{
//kullanılan RGB ortak anotlu olduğu için elde edilen değerlerin 255'ten çıkarılarak ters çevrilmesi gerekir. 
kirmizi=255- kirmizi;
yesil = 255 -yesil ;
mavi =255 -mavi;
//  0 ile 255 arasındaki analog değerler ilgili pinlere yazılır. 
analogWrite(kirmizipin, kirmizi);
analogWrite(yesilpin, yesil);
analogWrite(mavipin, mavi);
}

