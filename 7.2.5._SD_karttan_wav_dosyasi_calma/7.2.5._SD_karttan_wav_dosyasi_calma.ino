#include "SD.h"  //kütüphaneler koda eklenir. 
#define CSpin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm muzik;  //müzik adında bir nesne oluşturulur. Kütüphanedeki kodlar kullanılırken bu nesne isminin kullanılması zorunludur. 

void setup(){
muzik.speakerPin = 9; //ses çıkış pini olarak 9 nolu pin tanımlanır. 
Serial.begin(9600); //seri veri iletişimi başlatılır. 
if (!SD.begin(CSpin)) {  //eğer SD kart başlatılmazsa program hata verir. 
Serial.println("SD kart hatası...başlatılamadı");
return;
}
}

void loop(){ 
if(Serial.available()){    //seri port ekranından girilen rakamlara göre switch-case yapısı kullanılarak 3 çeşit müzik çalınır. 
switch(Serial.read()){
case '1': muzik.play("1.wav"); break; //eğer seri port ekranından 1 girilirse 1.müzik çalar. 
case '2': muzik.play("2.wav"); break; //2 girilirse 2.müzik çalar. 
case '3': muzik.play("3.wav"); break; //3 girilirse 3.müzik çalar. 
case '4': muzik.pause(); break;  //4 girilirse duraklat...4 e tekrar basılırsa kaldığı yerden devam eder. 
case '5': muzik.stopPlayback(); break;  //müzik durur. 
case '+': muzik.volume(1); break;  //+ tuşuna basılırsa ses şiddeti artar. 
case '-': muzik.volume(0); break;  //- tuşuna basılırsa ses şiddeti azalır. 
default: break;
}
}
}
