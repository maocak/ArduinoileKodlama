int ldrpin = 5; // 5 numaralı pin LDR pin olarak tanımlanır. 
int biteyaz = 9; //entegre veri,tetikleme ve biteyaz pinleri tanımlanır.  
int tetiklemepin = 10;
int veripin = 8;
int ledler=0; //ledler isimli bir değişkene ilk değeri atanır. 

void setup() {
Serial.begin(9600);
pinMode(biteyaz,OUTPUT); //Arduino çıkışları 8,9, 10 olarak tanımlanır. 
pinMode(veripin, OUTPUT);
pinMode(tetiklemepin, OUTPUT);
}

void loop() {
int deger= analogRead(ldrpin); //deger isimli değişkene LDR den okunan analog değer atanır. 
Serial.println(deger);
int yananledsayisi=deger/57; //  1023/9 analog değerini karşılık 1023/9= 114 sayısı bulunur. Daha sonra LDRye bağlana 10Klık dirençten dolayı 114 sayısınında yarısı alınır.
ledler=0;
for (int i=0; i<yananledsayisi;i++) //0 dan 9 kadar olan sayılar analog değerden sayıya göre bitSet yardımıyla shiftout komutuna yollanır. 
{
bitSet(ledler, i); 
}
kaydirmalikaydedici(); //yanan LED sayısını bulmak için fonksiyon çağrılır. 
}
void kaydirmalikaydedici()
{
//her bir LED için önce LOW değeri atanır, LSBFIRST ile 0. bitten başlayarak 7. bite doğru okunan değere göre ilgili LED yanar.
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, LSBFIRST, ledler);
digitalWrite(biteyaz, HIGH);
}
