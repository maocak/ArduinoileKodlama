#include <Adafruit_GFX.h> // LCD Nokia 5110 ekran için temel grafik kütüphane yüklenir.  
#include <Adafruit_PCD8544.h>  //Nokia 5110'larda bulunan PC8544 için Arduino sürücüsünü barındıran kütüphane 

// Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, DC, CS, RST);  
Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 7, 6);  //Nokia 5110 pin bağlantıları tanımlanır. 
 
int saniye=0;  //saniye isimli değişkene 0 atanır. 

void setup()  {  

Serial.begin(9600);  //seri veri iletişimi başlatılır. 
display.begin();  //LCD ekran başlatılır. 
display.setContrast(50);  //ekran kontrastını ayarlamak için sayı değiştirilebilir. 
display.clearDisplay();  //ekran temizlenir. 
 
display.setTextSize(2);  //yazı boyutu büyük ayarlanır. 
display.setTextColor(BLACK);  //yazı rengi siyah ayarlanır.(zemin rengi beyazdır.) Mono ekranlarda sadece Black ve White kullanılabilir. 
display.setCursor(0,0);  //sol üstten başlayarak orta font büyüklüğünde ArduinoDünyası yazısı yazar.
display.println("ArduinoDunyasi");  
//display.display(); 
display.setTextSize(1);  //yazı boyutu küçük ayarlanır. 
display.setTextColor(WHITE, BLACK); // yazı rengi beyaz,zemin rengi siyah olarak ayarlanır.  
display.println("Hosgeldiniz");  //Küçük font büyüklüğünde Hoşgeldiniz yazısı yazar. 
display.display();  
delay(5000);  
display.clearDisplay();  

}  

void loop() {  

for (int saniye=0; saniye<60; saniye+=1)  //0dan 59 a kadar saniye sayan sayaç for döngüsü içinde tanımlanır. 
{ 
//LCD ekranının çevresine diktörgen çizdirilir. Diktörtgenin 4 köşesi x0,y0,x1,y1 şeklinde tanımlanan çizgiler halinde birleştirilir. 
display.drawLine(0,0, 0, 47, BLACK);  
display.display();  
display.drawLine(0,47, 83, 47, BLACK);  
display.display();   
display.drawLine(0,0, 83, 0, BLACK);  
display.display();  
display.drawLine(83,0, 83, 47, BLACK);  

display.drawCircle(42, 24, 23, BLACK); //merkezi 42,24 olan ve yarıçapı 23 olan daire çizdirilir. 
display.display();  

display.setTextSize(2);  //saniye büyük fontta...
display.setTextColor(BLACK);  //siyah renkte...
display.setCursor(30,15);  //LCD ekranın ortasında...(x=30, y=15)
display.println(saniye);  //...yazdırılır.

display.setCursor(25,30); //(x=25, y=30)koordinatında...
display.setTextSize(1); //küçük font büyüklüğünde...
display.println("Saniye");  //saniye yazdırılır
display.display();  

delay(1000);  //1sn de bir yazdırılır. 
display.clearDisplay();  //döngünün her geçişinde ekran temizlenir, böylece sayaç gösterimi üst üste yazılmaz. 
}   
}  
