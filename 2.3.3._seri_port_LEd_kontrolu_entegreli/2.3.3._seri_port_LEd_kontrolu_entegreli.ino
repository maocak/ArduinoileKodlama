int biteyaz = 9; //latchpin= ST_CP (entegre belleğine kayıt pini)
int tetiklemepin = 10; //clockpin=SH_CP(kaydırmalı kaydedici tetikleme pini)
int veripin = 8; // datapin=DS (seri veri giriş pini)
byte ledler = 0; // ledler değişkenine byte olarak atama yapılır.
 
void setup() 
{
pinMode(biteyaz, OUTPUT); // kaydırmalı kaydediciyi kontrol etmek için pinler ayarlanır
pinMode(tetiklemepin, OUTPUT);  
pinMode(veripin, OUTPUT);
Serial.begin(9600); //seri port açılarak 9600 baud da veri iletişimi hazır hale getirilir. 
while (! Serial); // seriport hazır olana kadar bekler
Serial.println("0 ile 7 arasında LED numarasını giriniz/x tüm LEDleri söndürür"); //ekrana yazı //yazılır.
}
 
void loop() 
{
if (Serial.available())//eğer bir karakter girişi olursa ara bellekte hazır tutularak hazır hale //getirilir.
{
char deger = Serial.read();//okunup arabellekte tutulan karakter deger isminde değişkene //atılır.
if (deger >= '0' && deger <= '7')//değer değişkenine 0 ile 7 arasında karakter atandığında 
// koda işlemeye devam eder.
{
int led = deger ; //girilen her karakterden 0 çıkartılarak ASCII karakterine dönüştürülür. 
bitSet(ledler, led); // girilen karakter fonksiyona yollanır. 
kaydirmalikaydedici();
Serial.print(led);
Serial.println(" numaralı LED yandı "); //0-7 arası girilen numaraya göre ilgili LED yanar.
}
if ((deger == 'x') or (deger == 'X'))// eğer x karakteri girilirse 
{
ledler = 0;
kaydirmalikaydedici(); //karakter fonksiyona yollanır. 
Serial.println("LEDler söndü");
}
}
}
 
void kaydirmalikaydedici() 
{
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, LSBFIRST, ledler);
digitalWrite(biteyaz, HIGH);
}
