const int mavipin = 11;
const int yesilpin = 10;
const int kirmizipin = 9;
const int butonpin=7;
boolean oncekidurum = LOW;
boolean simdikidurum= LOW;
int leddurumu=0; //sayac olarak kullanılacak leddurumu değişkeninen ilk değeri atanır. 

void setup() {
// Arduino kartınmda mavi, yeşil ve kırmızı LEDleri kontrol edecek pinler çıkış olarak tanımlanır.   
pinMode(mavipin, OUTPUT);
pinMode(yesilpin, OUTPUT);
pinMode(kirmizipin, OUTPUT);
pinMode(butonpin, INPUT);// buton girişi tanımlanır.
digitalWrite(mavipin,HIGH);// İlk durumda RGB LEDin sönük başlaması için tüm LED lere HIGH atanır.  RBG LED ortak anotlu olduğu için HIGH söndürür.
digitalWrite(yesilpin,HIGH);
digitalWrite(kirmizipin,HIGH);
}
boolean butonkontrol(boolean simdi)//butonun basıldığını kontrol etmek için butonkontrol isminde bir fonksiyon tanımlanır. 
//boolean olarak deger LOW ya da HIGH değeri alabilir. 
{
boolean  butonhazir = digitalRead(butonpin); //okunan buton değeri butonhazir adlı bir değişkene atanır. 
if(simdi!=butonhazir) //loop dan gelen öncekidurum simdi olarak atanır. Eğer bu değer buton hazir değerine eşit değilse koşul sağlanır.
{
delay(100);// 100 msn geçikme sağlar. 
butonhazir=digitalRead(butonpin); //butonhazir değişkenine butonpin den okunan değer tekrar atanır. Bu değer ya LOW ya da HIGH dır. 
}
return butonhazir;//buton pinden gelen butonhazir değeri fonksiyon yardımıyla geri yollanır. 
}

void renkseti(int renk) //loop dan gelen 1,2,3,4,5 ve 6 koşullarına göre LEDlerin durumu belirlenir.
{
if(renk==1)
{
digitalWrite(kirmizipin,LOW); //kırmızı LED yanar
digitalWrite(yesilpin,HIGH); 
digitalWrite(mavipin,HIGH);  
}
else if(renk==2)
{
digitalWrite(kirmizipin,HIGH); //yeşil LED yanar. 
digitalWrite(yesilpin,LOW); 
digitalWrite(mavipin,HIGH);
}
else if(renk==3)
{
digitalWrite(kirmizipin,HIGH); //mavi LED yanar. 
digitalWrite(yesilpin,HIGH); 
digitalWrite(mavipin,LOW);
}
else if(renk==4)
{
analogWrite(kirmizipin,0);   // Sarı renk. RGB ortak anot olduğu için kırmızı ve yesil pinler 0 değeri aldığında aktif olarak sarı renki verir. 
analogWrite(yesilpin,0); 
analogWrite(mavipin,240);  
}
else if(renk==5)
{
analogWrite(kirmizipin,235); //Turkuaz renk. RGB ortak anot olduğu için yeşil ve mavi pinler 0 değer aldığında aktif olarak turkuaz rengi verir.  
analogWrite(yesilpin,0); 
analogWrite(mavipin,0);  
}
}

void loop()
{
simdikidurum=butonkontrol(oncekidurum); //Buton durumu basılmadan önce LOW, basıldığı and HIGH değerlerine koşula bağlayarak eğer butona
//basılırsa leddurumu sayacı 1 artırılır ve yukarda tanımlanan renkseti foksiyonu çağrılır. 
if(oncekidurum==LOW && simdikidurum==HIGH)
{
leddurumu++;
}
oncekidurum=simdikidurum;
if(leddurumu==6)
leddurumu=1; // 6 koşul tamamlandıktan sonra, başa dönerek kırmızı LEDin tekrar yanması sağlanır. 
renkseti(leddurumu); //yukarda tanımlanan renseti isimli fonksiyona 1,2,3,4,5 ve 6 sayılarını yollar. 
}
