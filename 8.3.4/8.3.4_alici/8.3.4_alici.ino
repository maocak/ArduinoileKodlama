//Kütüphaneler eklenir. 
#include <VirtualWire.h>
#include <LiquidCrystal.h>
// LCD ekran için pin tanımlamaları yapılır. 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Derece sembolü çizdirilir.
byte derecesembol[8] = {
B01100,
B10010,
B10010,
B01100,
B00000,
B00000,
B00000,
B00000  
};

int i;// değişken tanımlanır. 

void setup() {
lcd.begin(16,2);  // LCD tanımlanır ve başlatılır.
lcd.createChar(1, derecesembol);  // Derece sembolü 1 değişkenine atanarak oluşturulur.  
vw_setup(4800);  // Kütüphane iletişim hızı belirlenir.  
vw_rx_start();   // Veri alma işlemi başlatılır. 
vw_set_rx_pin(11); // Veri alma işlemi için kullanılacak pin atanır. 
lcd.clear();   // LCD ekran başlatılır. 
}

void loop() {
uint8_t buf[VW_MAX_MESSAGE_LEN];      // Gelen veriyi arabellekte tutacak değişken dizi olarak tanımlanır. 
uint8_t buflen = VW_MAX_MESSAGE_LEN;  // Gelen verinin uzunluğunu tutan değişken tanımlanır. 
lcd.setCursor(0,0);  //LCD ekran sol üst köşeden başlayarak...
lcd.print("Sicaklik: ");  // Sıcaklık yazar...
if (vw_get_message(buf, &buflen))    // Eğer veri alımı gerçekleşirse...
{
for (i=0;i<2;i++)  // Verinin ilk iki karakteri döngü içinde okutularak...
{
lcd.write(buf[i]);  // LCD ekrana yazdırılır. 
}  
lcd.write(1);  // Sıcaklık değerinden sonra derece sembolü yazdırılır. 
lcd.print("C"); 
lcd.setCursor(0,1); //2.satırdan itibaren...
lcd.print("Nem: "); //Nem yazdırılır 
for (i=2;i<4;i++)  // Son iki karakter döngü içinde okutularak...
{
lcd.write(buf[i]); // LCD ekrana yazdırılır.
}  
lcd.print("%"); //Nem değerinden sonra yüzdelik sembolü yazdırılır.      
}
}
