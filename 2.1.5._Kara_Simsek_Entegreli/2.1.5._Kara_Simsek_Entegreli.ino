int biteyaz = 9; //latchpin= ST_CP (entegre belleğine kayıt pini)
int tetiklemepin= 10; //clockpin=SH_CP(kaydırmalı kaydedici tetikleme pini)
int veripin = 8; // datapin=DS (seri veri giriş pini)
// entegrenin latch, clock ve data pinleri için Arduino çıkışları belirlenir 

// veridizi isminde her biri 1 baytlık 14 veri dizisi binary olarak tanımlanır. Böylece, sırasıyla 
//HIGH değeri 0. bitten 7. bite, 7.bitten tekrar 0. bite taşınacak şekilde uygun binary değerler 
//gönderilir. 
byte veridizi[14] = {
B00000001, 
B00000010, 
B00000100, 
B00001000, 
B00010000, 
B00100000, 
B01000000, 
B10000000, 
B01000000, 
B00100000, 
B00010000, 
B00001000, 
B00000100, 
B00000010, 
};

int sira = 0;
int sayac = 14 ;

void setup() {
pinMode(biteyaz, OUTPUT); // kaydırmalı kaydediciyi kontrol etmek için pinler ayarlanır.
pinMode(veripin, OUTPUT);  
pinMode(tetiklemepin, OUTPUT);
}
//veridizi içindeki 14 farklı 8 bitlik dizi değeri shiftOut ve digitalWrite komutları yardımıyla 
//gönderilerek LED’in HIGH durumuna geçmesi sağlanır. delay(100) komutu geçişler 
//arasında 0.01 saniye gecikme sağlar. sira++ ile bir sonkraki duruma geçiş sağlanır. İf 
//(sira>=sayaç) kontrolü ile tüm durumlar bittiğinde programın başa dönmesi sağlanır. 
void loop() {
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, MSBFIRST, veridizi[sira]);
digitalWrite(biteyaz, HIGH);
delay(600);
sira++;
if (sira >= sayac){
sira = 0;
}
}
