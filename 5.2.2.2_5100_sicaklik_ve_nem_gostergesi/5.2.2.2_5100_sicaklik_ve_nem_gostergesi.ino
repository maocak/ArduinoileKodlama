#include <Adafruit_GFX.h> // LCD Nokia 5110 ekran için temel grafik kütüphane çağrılır.  
#include <Adafruit_PCD8544.h>  //Nokia 5110'larda bulunan PC8544 için Arduino sürücüsünü barındıran kütüphane 
// Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, DC, CS, RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 7, 6);  //Nokia 5110 pin bağlantıları tanımlanır. 

#include <DHT.h>    //DHT kütüphanesi çağrılır. 
#define DHTPIN A2     //DHT11 in bağlanacağı pin numarası tanımlanır. 
#define DHTTYPE DHT11   //kullanılacak sensör türü DHT11 olarak atanır. Kütüphane aynı //zamanda DHT22 içinde çalıştığı için bunu belirtmemiz gerekir.
//Eğer DHT22 kullanılırsa kod #define DHTTYPE DHT22 şeklinde olmalıdır. 
 
DHT dht(DHTPIN, DHTTYPE);//pin çıkışı ve türü tanımlanan DHT11  
//1.karakter dizi olarak tanımlanır. 
static const unsigned char  PROGMEM karakter1[] =
{ 
0b00100,
0b10101,
0b01110,
0b11111,
0b01110,
0b01110,
0b10101,
0b00100
};
//2.karakter dizi olarak tanımlanır. 
static const unsigned char  PROGMEM karakter2[] =
{ 
B0001000,
B0001000,
B0001000,
B0010100,
B0100010,
B0100010,
B0011100 
};
//3.karakter dizi olarak tanımlanır. 
static const unsigned char  PROGMEM karakter3[] =
{ 
0b11111,
0b11111,
0b01001,
0b10010,
0b00100,
0b01000,
0b10000,
0b00000
};
//4.karakter dizi olarak tanımlanır. 
static const unsigned char  PROGMEM karakter4[] =
{ 
0b00000,
0b01110,
0b01110,
0b11111,
0b11111,
0b00000,
0b00000,
0b00000
};

void setup () {
  
Serial.begin(9600); //seri veri iletişimi başlatılır. 

display.begin();  //ekrtan başlatılır. 
display.setContrast(50);  //ekran kontrastını ayarlamak için sayı değiştirilebilir. 
display.clearDisplay();   //ekran temizlenir. 

dht.begin(); //DHT11 sensör başlatılır. 

// Program ilk çalıştırıldığında ekranda görülen yazıların özellikleri belirlenir  
display.setTextSize(1); //küçük yazı boyutu
display.setTextColor(BLACK);  //siyah renk 
display.setCursor(0,0);  
display.println("DHT11 ile");
display.setCursor(0, 8);
display.print("5110 ekranda");
display.setCursor(0, 16);
display.print("sicaklik/nem");  
display.setCursor(0, 24);
display.print("gosterimi");
display.setCursor(0, 32);
display.setTextColor(WHITE, BLACK); //son yazı beyaz siyah zemin rengi üzerine beyaz yazı ile belirlenir.
display.print("ArduinoDunyasi");
display.display();
delay (5000);
display.clearDisplay(); 
 
}

void loop () {
  
int nem = dht.readHumidity();  //DHT11 sensöründen okunan dijital değerler nem ve sıcaklık değişkenlerine atanır. 
int sicaklik = dht.readTemperature();  

display.setTextSize(3.5); //sıcaklık değerleri için boyut ayarlanır. 
display.setTextColor(BLACK);  //yazı rengi ayarlanır. 
display.setCursor(0,0);
display.print(sicaklik);  //sıcaklık değeri yazdırılır. 
display.setCursor(45,0);  //C karakterinin yeri belirlenir. 
display.print("C");   //C karakteri yazdırılır. 
display.setTextSize(1); //yazı boyutu ayarlanır. 
display.setTextColor(BLACK);  //yazı rengi ayarlanır. 
display.setCursor(65,0); //Derece karakterinin yeri belirlenir. 
display.print("o");  //Derece karakteri yazdırılır. 
display.display();

display.setTextSize(3); //nem değerleri için boyut ayarlanır. 
display.setTextColor(WHITE, BLACK); //nem değerleri siyah zemin üstüne beyaz olarak görülür. 
display.setCursor(0,26);  // yer belirlenir.
display.print(nem);  //nem değeri yazdırılır. 
display.setTextSize(1.5); //% karakterinin boyutu  belirlenir. 
display.setCursor(38,26);  //%karakterinin yeri belirlenir. 
display.print("%");
display.display();

// özel karakterlerin yeri, adı, boyutu tanımlanır. 
display.drawBitmap(65, 28,  karakter1, 8, 8, 1);
display.drawBitmap(70, 34,  karakter2, 8, 8, 1);
display.drawBitmap(55, 28,  karakter3, 8, 8, 1);
display.drawBitmap(60, 34,  karakter4, 8, 8, 1);
display.display();
   
delay (500);
display.clearDisplay();  
}
