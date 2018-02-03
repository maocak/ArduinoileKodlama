int biteyaz = 9; //latchpin= ST_CP (entegre belleğine kayıt pini)
int tetiklemepin = 10; //clockpin=SH_CP(kaydırmalı kaydedici tetikleme pini)
int veripin = 8; // datapin=DS (seri veri giriş pini)

//Analog A5 pini potansiyometre çıkışı olarak tanımlanır.
int potpin = 5;
//potdeger isminde bir değişkene ilk başlangıç değeri olan 0 atanır.
int potdeger = 0;

int ledler = 1; // ledler değişkenine byte olarak atama yapılır.
 
void setup() 
{ 
//Ardiuno pinleri(8,9,10) çıkış olarak tanımlanır.
pinMode(biteyaz, OUTPUT);
pinMode(veripin, OUTPUT);  
pinMode(tetiklemepin, OUTPUT);
}
 
void loop() 
{
//Analog girişten okunan değer potdeger değişkenine aktarılır.

int potdeger  = analogRead(potpin); 

int ledsayi = potdeger / 114;  // Okunan potdeger 0 ile1024 arasında olduğu için bu sayının 0 //ile 8 arasında LED sayısına bölünmesi gerekir. 0’dan 8’e kadar sayı değeri 9’dur. //Bundan //dolayı led sayısını kontrol edecek değeri bulmamız için analog değer olan 1023’ü 9’a //bölmemiz gerekir. 1023/9= 113,6 yaklaşık 114 sayısı bize 0’dan 8’e kadar LEDlerin //yanmasını sağlayacak ölçeklendirmeyi yapmayı sağlayacaktır.

ledler = 1;

for (int i = 0; i < ledsayi; i++) // 0 ile 8 arasında LEDleri yakmak için döngü içinde alınan //sayılar tek tek kaydirmalikaydedici() fonksiyonuna yollanarak ilgili LEDin yanması //sağlanır.
{
bitSet(ledler, i); 
}
kaydirmalikaydedici();
}
 
void kaydirmalikaydedici()
{
// her bir LED için önce LOW değeri atanır, LSBFIRST ile 0’dan //başlayarak 8. bite doğru //LEDler HIGH ile kaydırılarak yakılır.
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, LSBFIRST, ledler);
digitalWrite(biteyaz, HIGH);
}


