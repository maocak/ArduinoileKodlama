// kütüphane eklenir.
#include <LiquidCrystal.h>

// LCD pinlerinin Arduino UNO kartına bağlanacağı pinler tanımlanır
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup() {
// LCD'inin sütun ve satır sayısı belirtilerek başlatılır. 
lcd.begin(16, 2);
// seri veri iletişimi başlatılır.
Serial.begin(9600);
}

void loop() {
// seri porttan karakter girişi yapıldığı zaman...
if (Serial.available()) {
// yollanan karakterlerin ulaşması için 0,1 saniye beklenir.
delay(100);
// ekran temizlenerek hazır hale getirilir
lcd.clear();
// girilen karakterler okunur
while (Serial.available() > 0) {
// okunan karakterler LCD ekrana yazdırılır.
lcd.write(Serial.read());
}
}
}
