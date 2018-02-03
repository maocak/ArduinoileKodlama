#include <Adafruit_GFX.h>    // Temel grafik kütüphanesi
#include <SWTFT.h> // Donanıma özel kütüphane
#include <TouchScreen.h>  //Dokunmatik ekran kütüphanesi

//TFT kalkan için kullanılan pin tanımlamaları. 
#define YP A2  // Yplus, analog pin olmalıdır. 
#define XM A1  // Xminimum, analog pin olmalıdır. 
#define YM 6   // Yminimum, dijital pin olmalıdır. 
#define XP 7   // Xplus, dijital pin olmalıdır. 

//Dokunmatik ekran için Minimum ve Maksimum X ve Y değerleri/kalibrasyon değerleri atanır.
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

// Daha iyi basınç hassasiyeti X + ve X- arasında direnci bilmemiz gerekir. Multimetre kullanarak bu değer ölçülmektedir. 
// Bu uygulama için kullanılan TFT ekranın X değerleri arasındaki direnç 534R olarak ölçülmektedir. 
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 534); //Dokunmatik ekran kütüphanesini kullanmak için, ilk olarak bir Dokunmatik ekran nesnesi oluşturulur.

// 16 bit renk değerlerine atamalar yapılmıştır. 
#define	SIYAH     0x0000
#define	MAVI      0x001F
#define	KIRMIZI   0xF800
#define	YESIL     0x07E0
#define CAMGOBEGI 0x07FF
#define PEMBE     0xF81F
#define SARI      0xFFE0
#define BEYAZ     0xFFFF


SWTFT tft;

int eskirenk, yenirenk;

#define kutuboyut 40  //boxsize değeri olarak 40 atanır. 
#define yaricap 3 //penradius değeri olarak 3 atanır. 


#define minbasincdeger 10 //ekrana uygulanan minimum basınç değeri 10 atanır. 
#define maksbasincdeger 1000  //maksimum basınç değeeri 1000 atanır. 

void setup(void) {
  
Serial.begin(9600);
Serial.println(F("Boyama yapabilirsin!")); 
  
tft.reset(); //TFT ekran sıfırlanır. 
  
uint16_t identifier = tft.readID();//TFT ekranın sürücü numarası okunur. 

Serial.print(F("TFT LCD sürücü seri numarası: ")); //okunan numara ekrana yazdırılır. 
Serial.println(identifier, HEX); //Hexedecimal 
    

tft.begin(identifier); //TFT ekran başlatılır. 

tft.fillScreen(SIYAH);  //TFT ekran siyah yapılır. 

//x,y koordinatında, genişlik ve yüksekliği 40*40 olan ve 5 çeşit içi dolu kutucuk ekranın sol kenarına çizdirilir. 
tft.fillRect(0, 0, kutuboyut, kutuboyut, KIRMIZI);  //kırmızı kutucuk
tft.fillRect(kutuboyut, 0, kutuboyut, kutuboyut, SARI); //sarı kutucuk
tft.fillRect(kutuboyut*2, 0, kutuboyut, kutuboyut, YESIL);  //yeşil kutucuk
tft.fillRect(kutuboyut*3, 0, kutuboyut, kutuboyut, CAMGOBEGI);  //camgöbeği rengi kutucuk
tft.fillRect(kutuboyut*4, 0, kutuboyut, kutuboyut, MAVI);  //mavi kutucuk
tft.fillRect(kutuboyut*5, 0, kutuboyut, kutuboyut, PEMBE);  //macenta rengi kutucuk
  // tft.fillRect(kutuboyut*6, 0, kutuboyut, kutuboyut, BEYAZ);
 
tft.drawRect(0, 0, kutuboyut, kutuboyut, BEYAZ); //kırmızı kutunun çevresine beyaz renk çizgi çekilir. 
yenirenk = KIRMIZI; //kırmızı kutu seçilir. 
 
pinMode(13, OUTPUT); //13 nolu pin çıkış olaran tanımlanır. 
}



void loop()
{
digitalWrite(13, HIGH);
// Tanımlanan bir nokta nesnesi x y ve z koordinatlarını tutar 
// Eğer dokunmatik ekran kütüphanesinin ilk sürümleri kullanılırsa //içindeki komut denenmelidir. 
//  Point p = ts.getPoint();
TSPoint p = ts.getPoint(); //p nokta nesnesi
digitalWrite(13, LOW);

// TFT kalkanda kullanılan pin numaraları çıkış olarak tanımlanır. 
pinMode(XP, OUTPUT);
pinMode(XM, OUTPUT);
pinMode(YP, OUTPUT);
pinMode(YM, OUTPUT);

if (p.z > minbasincdeger && p.z < maksbasincdeger) { //eğer ekrana uygulanan basınç değeri 10 ile 1000 arasında ise
   
Serial.print("X koordinatı= "); Serial.print(p.x); //seri port ekranına x değeri yazdırılır. 
Serial.print("\tY koordinatı = "); Serial.print(p.y);  //y değeri yazdırılır. 
Serial.print("\tEkrana uygulanan basınç = "); Serial.println(p.z); //uygulanan basınç değeri yazdırılır. 

    
if (p.y < (TS_MINY-5)) {
Serial.println("Ekran silindi");
// Ekranı silmek için ekranın altında bulunan düğmeye basılır. 
tft.fillRect(0, kutuboyut, tft.width(), tft.height()-kutuboyut, SIYAH); //ekran silindikten sonra tekrar siyahla doldurulur.
}
// p nesnesinin x ve y koordinat değerleri belirlenir. 
p.x = tft.width()-(map(p.x, TS_MINX, TS_MAXX, tft.width(), 0));
p.y = tft.height()-(map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
   
if (p.y < kutuboyut) { //eğer p nesnesinin y değeri 40 tan küçükse
eskirenk = yenirenk; //eski renk değişkenine yeni renk değişkeni atanır. 

if (p.x < kutuboyut) { //x değeri 40 tan küçükse
yenirenk = KIRMIZI; //kırmızı renk atanır. 
tft.drawRect(0, 0, kutuboyut, kutuboyut, BEYAZ); //kırmızı kutucuk çevresi beyaz kare içine alınır. 
} else if (p.x < kutuboyut*2) { //x değeri 80 ten küçükse...
yenirenk = SARI; //sarı renk atanır. 
tft.drawRect(kutuboyut, 0, kutuboyut, kutuboyut, BEYAZ); //sarı kutucuk çevresi beyaz kare içine alınır. 
} else if (p.x < kutuboyut*3) {  //x değeri 120 ten küçükse...
yenirenk = YESIL; //yeşil renk atanır. 
tft.drawRect(kutuboyut*2, 0, kutuboyut, kutuboyut, BEYAZ); //yeşil kutucuk çevresi beyaz kare içine alınır.
} else if (p.x < kutuboyut*4) {  //x değeri 160 ten küçükse...
yenirenk = CAMGOBEGI;  //cam göbeği rengi atanır. 
tft.drawRect(kutuboyut*3, 0, kutuboyut, kutuboyut, BEYAZ);  //cam göbeği kutucuk çevresi beyaz kare içine alınır.
} else if (p.x < kutuboyut*5) {  //x değeri 200 ten küçükse...
yenirenk = MAVI;  //mavi renk atanır. 
tft.drawRect(kutuboyut*4, 0, kutuboyut, kutuboyut, BEYAZ);  //mavi kutucuk çevresi beyaz kare içine alınır.
} else if (p.x < kutuboyut*6) {  //x değeri 240 tan küçükse...
yenirenk = PEMBE;  //PEMBE renk atanır.
tft.drawRect(kutuboyut*5, 0, kutuboyut, kutuboyut, BEYAZ);  //PEMBE kutucuk çevresi beyaz kare içine alınır.
}
//eğer yeni bir renk seçilmezse beyaz kutu çerçeve eski rengin etrafında kalır. 
if (eskirenk != yenirenk) {
if (eskirenk == KIRMIZI) tft.fillRect(0, 0, kutuboyut, kutuboyut, KIRMIZI);
if (eskirenk == SARI) tft.fillRect(kutuboyut, 0, kutuboyut, kutuboyut, SARI);
if (eskirenk == YESIL) tft.fillRect(kutuboyut*2, 0, kutuboyut, kutuboyut, YESIL);
if (eskirenk == CAMGOBEGI) tft.fillRect(kutuboyut*3, 0, kutuboyut, kutuboyut, CAMGOBEGI);
if (eskirenk == MAVI) tft.fillRect(kutuboyut*4, 0, kutuboyut, kutuboyut, MAVI);
if (eskirenk == PEMBE) tft.fillRect(kutuboyut*5, 0, kutuboyut, kutuboyut, PEMBE);
}
}
if (((p.y-yaricap) > kutuboyut) && ((p.y+yaricap) < tft.height())) {
//ekranda seçilen renkte x ve y koordinatına göre yarıçapı 3 olan daire şeklinde noktalar yardımıyla çizimler yapılabilir. 
tft.fillCircle(p.x, p.y, yaricap, yenirenk);
}
}
}
