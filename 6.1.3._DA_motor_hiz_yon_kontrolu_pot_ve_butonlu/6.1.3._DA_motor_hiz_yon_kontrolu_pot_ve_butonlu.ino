const int LEDpin_sag=2;  //motor sağa dönünce yanacak ledin pini atanır.
const int LEDpin_sol=3;  //motor sola dönünce yanacak ledin pini atanır.

const int enablePin=5;  //L293D entegrenin enable pini atanır. 
const int motorpin_sag=6;  //motoru sağa döndüren pin atanır. 
const int motorpin_sol=7;  //motoru sola döndüren pin atanır. 

const int butonpin=8;  //buton pini atanır. 

const int potpin=A5;  //pot analog pin atanır. 
int deger;  //value değeri int olarak atanır. 

void setup() {

Serial.begin(9600);  //seri veri iletişimi başlatılır. 
pinMode(LEDpin_sag,OUTPUT); // LED pinleri çıkış olarak tanımlanır.
pinMode(LEDpin_sol,OUTPUT);

pinMode(butonpin, INPUT);  //buton pin giriş olarak tanımlanır. 

pinMode(motorpin_sag,OUTPUT); //motor sağ, sol ve enable pin çıkış olarak tanımlanır. 
pinMode(motorpin_sol, OUTPUT);
pinMode(enablePin,OUTPUT);
}

void loop() {
deger=analogRead(potpin); //okunan analog değer deger isimli değişkene atanır
deger=map(deger,0,1023,100,255); //deger isimli değişken 100 ile 250 arası çıkış değerine dönüştürülür
Serial.println(deger); //okunan değer seriport ekrana yazdırılır. 
analogWrite(enablePin, deger); //100 ile 250 arası okunan analog değer enablepin yardımıyla motorun hızını kontrol eder. 
delay(15);  

if(digitalRead(butonpin)== HIGH) //eğer sürgülü buton sağ tarafa çekilirse..
{
digitalWrite(motorpin_sag,HIGH); //motor sağa döner.
digitalWrite(motorpin_sol,LOW);
digitalWrite(LEDpin_sag, HIGH); //sağdaki LED yanar.
digitalWrite(LEDpin_sol, LOW);
}
else  //eğer sürgülü buton sol tarafa çekilirse...
{
digitalWrite(motorpin_sag, LOW);  
digitalWrite(motorpin_sol, HIGH); //motor sola döner.
digitalWrite(LEDpin_sag, LOW); 
digitalWrite(LEDpin_sol, HIGH);  //soldaki LED yanar. 
}
}
