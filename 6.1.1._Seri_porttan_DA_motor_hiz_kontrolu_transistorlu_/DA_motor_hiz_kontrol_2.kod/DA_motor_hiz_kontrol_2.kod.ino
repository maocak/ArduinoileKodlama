const int DAmotorpin = 3;

void setup() { 
//DA motor pini çıkış olarak tanımlanır.  
pinMode(DAmotorpin, OUTPUT); 
}

void loop() { 

digitalWrite(DAmotorpin, HIGH);  
delay(3000); // DA motor 3 saniye çalışır
digitalWrite(DAmotorpin, LOW);  
delay(3000); //DA motor 3 saniye durur
}
