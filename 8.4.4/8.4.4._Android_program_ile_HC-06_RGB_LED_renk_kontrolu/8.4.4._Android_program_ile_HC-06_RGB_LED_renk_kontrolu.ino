#include <SoftwareSerial.h> //kütüphane eklenir. 
int kirmiziLEDpin = 9; //LEDlerin pin numaraları atanır.
int yesilLEDpin = 10;
int maviLEDpin = 11;
SoftwareSerial BTserial(1, 0); //TX, RX pin bağlantıları tanımlanır. 
String renk; //renk isimli bir değişken string olarak tanımlanır. 

void setup() {
BTserial.begin(9600); //modülün iletişim hızı belirlenir. 
pinMode(kirmiziLEDpin, OUTPUT); //kırmızı LED pin çıkış olarak tanımlanır. 
pinMode(yesilLEDpin, OUTPUT); //yeşil LED pin çıkış olarak tanımlanır. 
pinMode(maviLEDpin, OUTPUT); //mavi LED pin çıkış olarak tanımlanır. 
}
void loop() {
while (BTserial.available()) { //eğer porttan herhangi bir veri girişi olursa...
delay(10); // biraz beklenir
char c = BTserial.read(); //modülden seri iletişim okunur ve c isimli değişkene atanır. 
renk += c ; //"kırmızı, yeşil ve mavi"  girişleri string olarak tanımlanır. 
}
if (renk.length() > 0) { //eğer modülün portundan gelen değer kırmızı ise(kırmızı butona basılırsa)...
if (renk == "red")
{
digitalWrite(kirmiziLEDpin, LOW);  //kırmızı LED yanar...
digitalWrite(yesilLEDpin, HIGH);
digitalWrite(maviLEDpin, HIGH);
delay(20);
}
else if (renk == "green")  //eğer yeşil butona basılırsa...
{
digitalWrite(kirmiziLEDpin, HIGH); //yeşil LED yanar. 
digitalWrite(yesilLEDpin, LOW);
digitalWrite(maviLEDpin, HIGH);
delay(20);
}
else if (renk == "blue")  //eğer mavi butona basılırsa...
{
digitalWrite(kirmiziLEDpin, HIGH);  //mavi LED yanar.
digitalWrite(yesilLEDpin, HIGH);
digitalWrite(maviLEDpin, LOW);
delay(20);
}
else if (renk == "stop") //eğer stop butonuna basılırsa...
{
digitalWrite(kirmiziLEDpin, HIGH);  //tüm LEDler söner...
digitalWrite(yesilLEDpin, HIGH);
digitalWrite(maviLEDpin, HIGH);
delay(20);
}
else if (renk == "fader")  //eğer Fader butonuna basılırsa...
{
analogWrite(kirmiziLEDpin, random(0,255)); //0-255 arası kırmızı, yeşil ve mavi renkte gelişigüzel renk ataması yapılır. 
analogWrite(yesilLEDpin, random(0,255));
analogWrite(maviLEDpin, random(0,255));
delay(250); //fader butonuna her basıldığında biraz bekler ve renk değişimi olur. 
}
renk = ""; //değişken sıfırlanır.
}
}
