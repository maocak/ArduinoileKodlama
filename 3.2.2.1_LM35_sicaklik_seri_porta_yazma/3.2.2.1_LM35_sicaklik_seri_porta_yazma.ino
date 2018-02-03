int sensorpin=5; //LM35 pini tanımlanır. 
float LM35deger; //LM35 çıkışındaki büyüklüğü ölçmek için LM35 isminde bir değişken tanımlanır.
float analogdeger; //analogdeger isimli bir değişken tanımlanır. 

void setup () {
Serial.begin(9600); //Seri veri iletişimi başlatılır.
}

void loop () {
analogdeger = analogRead(sensorpin); //LM35 çıkışından(A5) okunan analog sayı analogdeger isimli değişkene atanır.
analogdeger = (analogdeger/1023)*5000;//0-1023 arası okunan analog değer mV'a dönüştr 
LM35deger = analogdeger /10; // Okunan mV  sicakliğa dönüştürülerek LM35 isimli değişkene atanır. 
Serial.print("Ölçülen sıcaklık degeri: "); //Seri port ekranına  "Ölçülen sıcaklık degeri:" yazdırılır.
Serial.print (LM35deger); //LM35'den okunan değer seriport ekranına yazdırılır.
Serial.println (" C");
delay (2000); //sensörden okuma her 2 saniyede bir gerçekleşir. 

}
