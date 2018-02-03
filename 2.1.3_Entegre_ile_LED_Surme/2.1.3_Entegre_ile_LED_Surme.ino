int biteyaz = 9; //latchpin= ST_CP (entegre belleğine kayıt pini)
int tetiklemepin= 10; //clockpin=SH_CP(kaydırmalı kaydedici tetikleme pini)
int veripin = 8; // datapin=DS (seri veri giriş pini)
// entegrenin latch, clock ve data pinleri için Arduino çıkışları belirlenir 

byte ledler = 1; // ledler değişkenine byte olarak atama yapılır.
 
void setup() 
{
pinMode(biteyaz, OUTPUT); // kaydırmalı kaydediciyi kontrol etmek için pinler ayarlanır
pinMode(veripin, OUTPUT);  
pinMode(tetiklemepin, OUTPUT);
}
 
void loop()  // 0’dan 7’ye kadar tanımlanan kaydirmalikaydedici fonkisyonu içinde bulunan LSBFIRST komutuna sırasıyla değer yollanır ve tekrarlar. 
{
ledler = 1; // döngü tamamlandığında 1.veri setinin (byte) tekrar başlamasını sağlar
kaydirmalikaydedici();
delay(500);
 
bitSet(ledler, 0);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 1);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 2);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 3);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 4);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 5);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 6);
kaydirmalikaydedici();
delay(500);
    
bitSet(ledler, 7);
kaydirmalikaydedici();
delay(500);
}
 
void  kaydirmalikaydedici() 
// her bir LED için önce LOW değeri atanır, LSBFIRST ile 0’dan 
//başlayarak 7. bite doğru LEDler HIGH ile kaydırılarak yakılır. 
{
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, LSBFIRST, ledler);
digitalWrite(biteyaz, HIGH);
}

