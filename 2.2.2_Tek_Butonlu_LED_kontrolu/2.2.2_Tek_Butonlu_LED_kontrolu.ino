int diziled[] = {8, 9, 10, 11};// 4 adet ledi tanımlayan bir dizi oluşturulmuştur.
int sayi = 4; //led sayısı kadar sayi değişkenine değer atanır. 
int butonpin = 7; // butonpin değişkenine 7 nolu pin tanımlanır. 
int butondurumu = 0; // buton değeri olarak başlangıç için deger isimli değişkene 0 atanır. 
int butonbassayac = 0; //

void setup() {
for (int i = 0 ; i < sayi ; i++) 
{
pinMode(diziled[i], OUTPUT); // Arduino kartında led çıkışları  8,9,10 ve 11 olarak atanır. 
}
pinMode(butonpin, INPUT); //Arduino kartında buton basıldığında giriş değeri alınacak pin atanır. 
}

void loop() {
butondurumu = digitalRead(butonpin); //deger isimli değişkene butonun durumu atanır. Bu durum buton basıldığında HIGH, serbest bırakıldığında LOW'dur. 
if (butondurumu == HIGH) // butonbassayac arttıkça Led1'den Led4'e kadar her defasında bir led pini çıkışı HIGH diğer üçü LOW olacak şekilde döngü sağlanır.  
{
for (int i = 0 ; i < sayi ; i++)
{
if (butonbassayac % sayi == i)
digitalWrite(diziled[i], HIGH);
else
digitalWrite(diziled[i], LOW);
}
butonbassayac++; //sayaç 1 artar
delay(200); //2msn geçikme sağlar. 
}
}
