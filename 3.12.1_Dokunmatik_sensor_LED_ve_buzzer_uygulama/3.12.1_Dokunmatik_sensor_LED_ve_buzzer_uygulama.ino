int yesilLED = 5; // RGB Yeşil LED pin nosu tanımlanır. 
int kirmiziLED = 6; //RGB kırmızı LED pin nosu tanımlanır. 
int buzzerpin = 7;  //Buzzer pin nosu tanımlanır. 
int dokunmatiksensor = 3; //sensör pin  nosu tanımlanır.
int deger; //deger isminde değişken tanımlanır.

void setup ()
{
Serial.begin(9600); //Seri veri iletişimi başlatılır. 
pinMode (yesilLED, OUTPUT); //RGB yeşil LED pin çıkış olarak atanır.
pinMode (kirmiziLED, OUTPUT); //RGB kırmızı LED pin çıkış olarak atanır. 
pinMode (buzzerpin, OUTPUT);  //Buzzer pin çıkış olarak atanır. 
pinMode (dokunmatiksensor, INPUT); //Sensör pini giriş olarak atanır. 
}
void loop ()
{
deger = digitalRead (dokunmatiksensor); //sensörden okunan değer, deger isimli değişkene atanır. 
Serial.println(deger); //okunan değer ekrana yazdırılır.
if (deger == HIGH) //Eğer okunan değer HIGH ise...
{
digitalWrite (kirmiziLED, LOW); //Kırmızı LED yanar
digitalWrite (yesilLED, HIGH);  //Yeşil LED söner
tone(buzzerpin, 440);  //Buzzer ses çıkarır.
}
else // Eğer okunan değer HIGH değilse...
{
digitalWrite (kirmiziLED, HIGH); //Kırmızı LED söner
digitalWrite (yesilLED, LOW); //Yeşil LED yanar
noTone(buzzerpin); //Buzzer ses vermez.
}
}
