#include <MaxMatrix.h>  //kullanılacak kütüphane çağrılır.
int DIN = 12;   // MAX7219 entegrenin DIN pini tanımlanır.
int CS = 11;   // MAX7219 entegrenin CS pini tanımlanır.
int CLK = 10;    // MAX7219 entegrenin CLK pini tanımlanır.
int entegresayi = 1;  //entegresayi 1 değeri atanır. 
int k=7;  //k değişkenine 7 değeri atanır.
int j;  //j değişkeni tanımlanır. 

MaxMatrix entegre(DIN, CS, CLK, entegresayi);  //kaç adet MAX7219 kullanılacağı ve pinleri
//tanımlar.(bu deneyde 1 adet dotmatriks isminde bir entegre tanımlanmaktadır)
//binary sistemde kayan yüz değerleri dizi içinde atanır.           
char kayanyuz[] = {8, 8,
                  B00111100,
                  B01000010,
                  B10010101,
                  B10100001,
                  B10100001,
                  B10010101,
                  B01000010,
                  B00111100
                 };
void setup() {
entegre.init(); // MAX7219 başlatılır.
entegre.setIntensity(8); // led matriksin ışık şiddeti ayarlanır ( 0 ile 15 arasında bir değer olabilir)
}

void loop() {
// (3,3), (4,3), (3,4), (4,4) koordinatlarındaki LEDler sırayısla 1sn aralıkla yanar.
entegre.setDot(3,3,true); 
delay(1000);
entegre.setDot(4,3,true);
delay(1000);
entegre.setDot(3,4,true); 
delay(1000);
entegre.setDot(4,4,true);
delay(1000);

entegre.clear(); // Ekran temizlenir.
// (0,0)dan başlayarak (7,7)ye kadar sol üstten sağ alta eğik çizgi çeker.  
for (int i=0; i<8; i++){
entegre.setDot(i,i,true);
delay(300);
}
entegre.clear(); //ekran temizlenir. 
//(7,0)dan başlayarak (0,7)ye sağ üstten sol alta ters eğik çizgi çeker. 
for (int j=0; j<8; j++){
entegre.setDot(k, j,true);
delay(300); 
k--;
}
entegre.clear(); //Ekran temizlenir. 
// Dizi olarak tanımlanan yüz karakteri (0,0)dan başlayarak ekrana gelir. 
entegre.writeSprite(0, 0, kayanyuz);
delay(1000); //1 saniye geçikme yaşanır. 

//shiftLeft komutu ile ekrandaki yüz karakteri sola doğru kayarak kaybolur.
for (int i=0; i<8; i++){ 
entegre.shiftLeft(false,false);
delay(300);
}
entegre.clear(); //Ekran temizlenir.
k=7; //2.döngüde bulunan ters çizgi için ilk değer tekrar 7 atanır.
}
