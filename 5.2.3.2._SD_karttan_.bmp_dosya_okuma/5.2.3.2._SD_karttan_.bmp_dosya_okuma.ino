#include <SPI.h>            // SPI haberleşme kütüphanesi
#include <SD.h>             // mikro SD kart kütüphanesi
#include <Adafruit_GFX.h>   // Temel grafik kütüphanesi
#include <MCUFRIEND_kbv.h>  //Arduino UNO için geliştirilen TFT kütüphanesi

MCUFRIEND_kbv tft;

#if defined(ESP32)
#define SD_CS     5
#else
#define SD_CS     10
#endif
#define NAMEMATCH ""        // "" herhangi bir isim olabilir. 

#define PALETTEDEPTH   0     // Palet modları desteklenmemektedir. Bunun için 0 kullanılmıştır. 

char namebuf[32] = "/";   //bmp dosyalar mikro SD kartın kök klasörü içine konulmalıdır.

File root;
int pathlen;

void setup()
{
uint16_t ID;
Serial.begin(9600); //seri veri iletişimi başlatılır. 
Serial.print("TFT ekranda gösterilen .bmp uzantılı resimler. Seri numarasıID:0x");
ID = tft.readID();  //ekran sürücü numarası okunur. 
Serial.println(ID, HEX);  //ekrana yazdırılır. 
if (ID == 0x0D3D3) ID = 0x9481;
tft.begin(ID); //TFT ekran başlatılır. 
tft.fillScreen(0x001F);
tft.setTextColor(0xFFFF, 0x0000);
bool good = SD.begin(SD_CS); //mikro SD kart başlatılır. 
if (!good) {
Serial.print(F("SD kart okunamıyor!")); //Eğer başlatılamazsa seri port ekranına uyarı verir. 
while (1);  //program kitlenir. 
}

root = SD.open(namebuf); //SD kart okunmaya hazır hale getirilir. 
pathlen = strlen(namebuf);
}

void loop()
{
char *nm = namebuf + pathlen;
File f = root.openNextFile();
uint8_t ret;
uint32_t start;
if (f != NULL) {
#ifdef USE_SDFAT
f.getName(nm, 32 - pathlen);
#else
strcpy(nm, (char *)f.name());
#endif

f.close();
strlwr(nm);

if (strstr(nm, ".bmp") != NULL && strstr(nm, NAMEMATCH) != NULL) {
Serial.print(namebuf);
Serial.print(F(" - "));
tft.fillScreen(0);
start = millis();
ret = showBMP(namebuf, 5, 5);

switch (ret) { //ret fonksiyonunda tanımlanan okuma hatalarına göre ekranda hata mesajları belirir. 
case 0:
Serial.print(millis() - start);
Serial.println(F(" milisaniye")); //bmp formatında dosyalar sırasıyla okunur ve okuma hızları seriport ekrana yazdırılır. 
delay(5000);
break;
//okuma hatalarına göre oluşan durumlar şu şekildedir
case 1:
Serial.println(F("yanlış pozisyon"));
break;

case 2:
Serial.println(F("yanlış bmp numarası"));
break;

case 3:
Serial.println(F("yanlış renk numaraları"));
break;

case 4:
Serial.println(F("desteklenmeyen bmp formatı"));
break;

case 5:
Serial.println(F("desteklenmeyen palet"));
break;
default:
Serial.println(F("bilinmiyor"));
break;
}
}
}
else root.rewindDirectory(); //hata yoksa tekrar dosyaları okumak için başa döner. 
}

#define BMPIMAGEOFFSET 54
#define BUFFPIXEL      20

uint16_t read16(File& f) {
uint16_t result;         // 16 bit formatında dosyalar okunarak boyutu belirlenir...
f.read((uint8_t*)&result, sizeof(result));
return result;  //boyut döndürülür.
}

uint32_t read32(File& f) { //32 bit formatında dosyalar okunarak boyutu belirlenir...
uint32_t result;
f.read((uint8_t*)&result, sizeof(result));
return result;  //okunan boyut döndürülür.
}

uint8_t showBMP(char *nm, int x, int y) //showBMP adlı fonksiyon tanımlanır. 
{
File bmpFile;
int bmpWidth, bmpHeight;    // piksel cinsinden genişlik ve yükseklik tanımlanır.  
uint8_t bmpDepth;           // bit derinliği tanımlanır. derinlik  24, 16, 8, 4, 1 den biri olmalıdır. 
uint32_t bmpImageoffset;    // Dizinde bulunan resimlerin okunması yapılır. 
uint32_t rowSize;           // satırboyutu tanımlanır. 
uint8_t sdbuffer[3 * BUFFPIXEL];    // arabellekte okunan pixel değeri tanımlanır. 
uint16_t lcdbuffer[(1 << PALETTEDEPTH) + BUFFPIXEL], *palette = NULL;
uint8_t bitmask, bitshift;
boolean flip = true;        // dosyalarınn gösterimi dik olarak aşağıdan yukarıya doğru tanımlanır.  
int w, h, row, col, lcdbufsiz = (1 << PALETTEDEPTH) + BUFFPIXEL, buffidx;
uint32_t pos;               // resim pozisyonu tanımlanır.  
boolean is565 = false;      //

uint16_t bmpID;
uint16_t n;                 // değişkenler tanımlanır. 
uint8_t ret;

if ((x >= tft.width()) || (y >= tft.height())) //eğer resim genişlik ve yükseklik olarak ekran sığmazsa...
return 1;               // hata döndürülür. 

bmpFile = SD.open(nm);      // bmp dosyası ayrıştırma başlığı açılır. 
bmpID = read16(bmpFile);    // bmp dosyası imzası 16 bit formatında okunur.  
(void) read32(bmpFile);     // Dosya boyutu okunur ya da göz ardı edilir. 
(void) read32(bmpFile);     // İçerik oluşturucu baytları okunur yada yoksayılır. 
bmpImageoffset = read32(bmpFile);       // görüntü verisi başlatılır. 
(void) read32(bmpFile);     // dib başlık boyutu okunur ya da yoksayılır. 
bmpWidth = read32(bmpFile);
bmpHeight = read32(bmpFile);
n = read16(bmpFile);        // renk numaraları 16 bit formatında atanır. 
bmpDepth = read16(bmpFile); // her pixel değeri bir bite karşılık gelir. 
pos = read32(bmpFile);      // renk numaraları 32 bit formatında atanır.
if (bmpID != 0x4D42) ret = 2; // yanlış bmp numarası
else if (n != 1) ret = 3;   // çok fazla renk değerleri mevcuttur. 
else if (pos != 0 && pos != 3) ret = 4; // desteklenmeyen bmp formatı: 0 = sıkıştırılamamış, 3 = 565 anlamına gelir. 
else if (bmpDepth < 16 && bmpDepth > PALETTEDEPTH) ret = 5; // desteklenmeyen palet derinliği
else {
bool first = true;
is565 = (pos == 3);               // ?already in 16-bit format
// bmp satırları, 4 bayt sınırına (gerekirse) doldurulur
rowSize = (bmpWidth * bmpDepth / 8 + 3) & ~3;
if (bmpHeight < 0) {              // Okunan değer negatifse, resim yukardan-aşağıya doğru gösterilecek şekilde atanır. 
bmpHeight = -bmpHeight;
flip = false;
}

w = bmpWidth;  //genişlik ve yükseklik değerleri atanır. 
h = bmpHeight;

if ((x + w) >= tft.width())       // kırpılmış resim alanı yüklenir. 
w = tft.width() - x;
if ((y + h) >= tft.height())      //
h = tft.height() - y;

if (bmpDepth <= PALETTEDEPTH) {   // Burda kullanılan modlar farklı paletlere sahiptir. 
bmpFile.seek(BMPIMAGEOFFSET); //palette is always @ 54
bitmask = 0xFF;
if (bmpDepth < 8)
bitmask >>= bmpDepth;
bitshift = 8 - bmpDepth;
n = 1 << bmpDepth;
lcdbufsiz -= n;
palette = lcdbuffer + lcdbufsiz;
for (col = 0; col < n; col++) {
pos = read32(bmpFile);    //16 bit 5-6-5 renk derinliği palet modeli tanımlanır. 
palette[col] = ((pos & 0x0000F8) >> 3) | ((pos & 0x00FC00) >> 5) | ((pos & 0xF80000) >> 8);
}
}

// TFT adres penceresinini kırpılmış görüntü sınırları ayarlanır. 
tft.setAddrWindow(x, y, x + w - 1, y + h - 1);

for (row = 0; row < h; row++) { // satırdaki piksellerin taraması yapılır. 
//Bunu yapmak yoğun bir iştir, ancak kırpma gibi durumlarda ekranı daha etkili doldurur. 
//Aynı zamanda, SD kütüphanesinde birçok matematiksel hesaplamanın önüne geçer.
}
uint8_t r, g, b, *sdptr;
int lcdidx, lcdleft;
if (flip)   // normal bmp modu (aşağıdaan yukarı)saklanır. 
pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
else        // Eğer değilse yukarıdan-aşağıya saklanır. 
pos = bmpImageoffset + row * rowSize;

if (bmpFile.position() != pos) { 
bmpFile.seek(pos);
buffidx = sizeof(sdbuffer); // arabellekte tekrar yüklemeye zorlanır. 
}

for (col = 0; col < w; ) {  //sütundaki piksellerin taraması yapılır. 
lcdleft = w - col;
if (lcdleft > lcdbufsiz) lcdleft = lcdbufsiz;

for (lcdidx = 0; lcdidx < lcdleft; lcdidx++) { //arabelleğe sütunlar sırasıyla alınır
uint16_t color;
// piksel verisi okumaya devam eder. 
if (buffidx >= sizeof(sdbuffer)) { 
bmpFile.read(sdbuffer, sizeof(sdbuffer));
buffidx = 0; // indeks numarası tekrar başlangıca döner
r = 0;
}

switch (bmpDepth) {    // Pixel değerleri bmp den TFT formatına dönüştürülür. 
case 24:
b = sdbuffer[buffidx++];
g = sdbuffer[buffidx++];
r = sdbuffer[buffidx++];
color = tft.color565(r, g, b);
break;
case 16:
b = sdbuffer[buffidx++];
r = sdbuffer[buffidx++];
if (is565)
color = (r << 8) | (b);
else
color = (r << 9) | ((b & 0xE0) << 1) | (b & 0x1F);
break;
case 1:
case 4:
case 8:
if (r == 0)
b = sdbuffer[buffidx++], r = 8;
color = palette[(b >> bitshift) & bitmask];
r -= bmpDepth;
b <<= bmpDepth;
break;
}
lcdbuffer[lcdidx] = color;
}
tft.pushColors(lcdbuffer, lcdidx, first);
first = false;
col += lcdidx;
tft.setAddrWindow(0, 0, tft.width() - 1, tft.height() - 1); //tüm ekran özelliği tekrar aktif hale getirilir. 
ret = 0;        // ret fonksiyonuna 0 değeri döndürülür. 
}
bmpFile.close();
return (ret);
}

