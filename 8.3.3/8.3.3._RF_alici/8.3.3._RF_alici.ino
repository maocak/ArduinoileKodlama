#include <VirtualWire.h> //kütüphaneler koda eklenir. 
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //LCD ekran pin atamaları yapılır. 

byte veri[VW_MAX_MESSAGE_LEN]; //gelen mesajları saklamak için veri isimli dizi arabellekte oluşturulur. 
byte veriuzunluk = VW_MAX_MESSAGE_LEN; //gelen verinin karakter uzunluğunu kullanmak için bir değişken tanımlanır. 
int i;
int sutun = 0; //LCD ekranın sutun numarasını belirleyecek bir değişkene 0 atanır. 

void setup()
{
lcd.begin(16, 2); //LCD ekran başlatılır. 
lcd.setCursor(3, 0); //3.sutun, 1. satırda başlayarak Cihaz hazır mesajı yayınlanır. Bu mesaj alınmazsa vericiden veri gelmiyor demektir. 
lcd.print("Cihaz hazir!");
vw_setup(2000); //kütüphane başlatılır. 2000 saniyede yollanacak bit sayısını belirtir. 
vw_rx_start();  //veri alma işlemi başlatılır. 
}
void loop()
{

if( vw_get_message(veri, &veriuzunluk) ) //eğer alıcı yollanan veriyi alırsa...
{
if (sutun==17){lcd.clear();sutun=0;lcd.setCursor(sutun, 1);} //sütun sayısı 16 olduğunda(ekranın sonuna ulaşıldığında) ekran temizlenir ve yazma işlemi 2.satırdan itibaren devam eder. 
lcd.setCursor(0, 0); //LCD ekranın sol üst köşesinden itibaren 0 dan başlayarak... 
lcd.print(sutun);  //veri geldikçe karakter sayısı yazmaya başlar.
lcd.setCursor(sutun, 1); //2.satırdan başlayarak...  
for (i = 0; i < veriuzunluk; i++) //yazma işlemi girilen karaterin uzunluğu boyunca devam eder...
{
lcd.print((char)veri[i]); //veri dizisine atanan karakterler teker teker yazmaya başlar.
}
sutun++;  //her karakterden sonra dizi elemanı 1 artırılır...
}
}



