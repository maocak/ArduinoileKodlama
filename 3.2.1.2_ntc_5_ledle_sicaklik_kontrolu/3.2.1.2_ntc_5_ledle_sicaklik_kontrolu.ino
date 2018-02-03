int sensorpin=0;//sensorpin isimli değişkene ilk değer 0 atanır. 
int birinciled=12; //değişkenlere 8-12 arası tamsayı atamaları yapılır.
int ikinciled=11;
int ucunculed=10;
int dordunculed=9;
int besinciled=8;

void setup() {
Serial.begin(9600);
pinMode(birinciled, OUTPUT); //1-5 arası LED ler için 8-12 pinler çıkış olarak atanır. 
pinMode(ikinciled, OUTPUT);
pinMode(ucunculed, OUTPUT);
pinMode(dordunculed, OUTPUT);
pinMode(besinciled, OUTPUT);
}

void loop() {
sensorpin=analogRead(0); //A0 çıkışından okunan analog değer sensorpin değişkenine atanır. 
if(sensorpin>580) //okunan değer 580 ten büyükse tüm LEDler yanar. Ekrana '5 LED YANDI' yazar.
{
digitalWrite(birinciled, HIGH);
digitalWrite(ikinciled, HIGH);
digitalWrite(ucunculed, HIGH);
digitalWrite(dordunculed, HIGH);
digitalWrite(besinciled, HIGH);
Serial.println("5 LED YANDI");
Serial.println(sensorpin);
}
else if (sensorpin>=570 && sensorpin<580) //okunan değer bu aralıkta ise 4 tane LED yanar. Ekrana '4 LED YANDI' yazar.
{
digitalWrite(birinciled, LOW);
digitalWrite(ikinciled,HIGH);
digitalWrite(ucunculed,HIGH);
digitalWrite(dordunculed,HIGH);
digitalWrite(besinciled,HIGH);
Serial.println("4 LED YANDI");
Serial.println(sensorpin);
}
else if(sensorpin>=560 && sensorpin<570) //okunan değer bu aralıkta ise 3 LED yanar. Ekrana '3 LED YANDI' yazar.
{
digitalWrite(birinciled,LOW);
digitalWrite(ikinciled,LOW);
digitalWrite(ucunculed,HIGH);
digitalWrite(dordunculed,HIGH);
digitalWrite(besinciled,HIGH);
Serial.println("3 LED YANDI");
Serial.println(sensorpin);
}
else if(sensorpin>=550 && sensorpin<560 )//okunan değer bu aralıkta ise 2 LED yanar. Ekrana '2 LED YANDI' yazar.
{
digitalWrite(birinciled,LOW);
digitalWrite(ikinciled,LOW);
digitalWrite(ucunculed,LOW);
digitalWrite(dordunculed,HIGH);
digitalWrite(besinciled,HIGH);
Serial.println("2 LED YANDI");
Serial.println(sensorpin);
}
else if(sensorpin>=540 && sensorpin<550)//okunan değer bu aralıkta ise 1 LED yanar. Ekrana '1 LED YANDI' yazar.
{
digitalWrite(birinciled,LOW);
digitalWrite(ikinciled,LOW);
digitalWrite(ucunculed,LOW);
digitalWrite(dordunculed,LOW);
digitalWrite(besinciled,HIGH);
Serial.println("1 LED YANDI");
Serial.println(sensorpin);
}
else if(sensorpin<540 ) //okunan değer bu aralıkta ise Tüm LEDler söner. Ekrana 'Tüm LEDler sönük' yazar. 
{
digitalWrite(birinciled,LOW);
digitalWrite(ikinciled,LOW);
digitalWrite(ucunculed,LOW);
digitalWrite(dordunculed,LOW);
digitalWrite(besinciled,LOW);
Serial.println("Tüm LEDler sönük");
Serial.println(sensorpin);
}
delay(100); //1milisaniye bekler.
}

