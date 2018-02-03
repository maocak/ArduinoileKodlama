float LM35deger; //LM35 çıkışındaki büyüklüğü ölçmek için LM35 isminde bir değişken tanımlanır.
float analogdeger; //analogdeger isimli bir değişken tanımlanır. 
int sensorpin = 5; //LM35 pini tanımlanır. 
// 3,5 ve 6 nolu pinlere sırasıyla kırmızı, yeşil ve mavi LED çıkışları tanımlanır.
int kirmiziLEDpin = 3; 
const int yesilLEDPin = 5; 
const int maviLEDPin = 6;

void setup() 
{
Serial.begin(9600); //Seri veri iletişimi başlatılır.
//kırmızı, yeşil ve mavi LED pinleri çıkış olarak tanımlanır. 
pinMode(kirmiziLEDpin, OUTPUT);
pinMode(yesilLEDPin, OUTPUT);
pinMode(maviLEDPin, OUTPUT); 
}
 
void loop()
{
analogdeger = analogRead(sensorpin); //LM35 çıkışından(A5) okunan analog sayı analogdeger isimli değişkene atanır.
analogdeger = (analogdeger/1023)*5000;//0-1023 arası okunan analog değer mV'a dönüştr 
LM35deger = analogdeger /10; // Okunan mV  sicakliğa dönüştürülerek LM35 isimli değişkene atanır. 
if(LM35deger<16)//beyaz yanar
{
digitalWrite(maviLEDPin, LOW);
digitalWrite(yesilLEDPin, LOW);
digitalWrite(kirmiziLEDpin, LOW);
}
else if (LM35deger<20)//yeşil yanar
{
digitalWrite(maviLEDPin, HIGH);
digitalWrite(yesilLEDPin, LOW);
digitalWrite(kirmiziLEDpin, HIGH);
}
else if (LM35deger<24)//mavi yanar
{
digitalWrite(maviLEDPin, LOW);
digitalWrite(yesilLEDPin, HIGH);
digitalWrite(kirmiziLEDpin, HIGH);
}
else if (LM35deger<28) //sarı yanar
{
digitalWrite(maviLEDPin, HIGH);
digitalWrite(yesilLEDPin, LOW);
digitalWrite(kirmiziLEDpin, LOW);
}
else //kırmızı yanar
{
digitalWrite(maviLEDPin, HIGH);
digitalWrite(yesilLEDPin, HIGH);
digitalWrite(kirmiziLEDpin, LOW);
}
Serial.print("Ölçülen sıcaklık degeri: "); //Seri port ekranına  "Ölçülen sıcaklık degeri:" yazdırılır.
Serial.print (LM35deger); //LM35'den okunan değer seriport ekranına yazdırılır.
Serial.println (" C");
delay (2000); //sensörden okuma her 2 saniyede bir gerçekleşir. 
}
