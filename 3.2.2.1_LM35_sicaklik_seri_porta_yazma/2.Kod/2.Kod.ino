float LM35deger;
int analogdeger;
int sensorpin = 5;

void setup()
{
analogReference(INTERNAL); //Arduino UNO kartında 1.1 V dur. 
Serial.begin(9600);
}

void loop()
{
analogdeger = analogRead(sensorpin);
LM35deger = analogdeger / 9.31; //Her bir derece 9.31’e eşittir. 
Serial.print("Ölçülen sıcaklık degeri: ");
Serial.print(LM35deger);
Serial.println (" C");
delay(2000);
}
