int buzzerpin=3; //Buzzer pini tanımlanır.

void setup()
{
}

void loop()
{
tone(buzzerpin, 440); //Buzzer 440 Hertz şiddetinde ve 1 saniye ses çıkarır. 
delay(1000);
noTone(buzzerpin); // İlk ses durur. 
tone(buzzerpin, 540); //540 Hertz lik 2. ses çalmaya başlar. 
delay(1000); //2. ses de 1 saniye sürer.  
noTone(buzzerpin); //2. ses susar ve döngü tekrar baştan başlar.  

}
