int ledpin = 13;     // LED pini tanımlanır. 
int sensorpin = 2;   // PIR sensör pini tanımlanır. 
int pirState = LOW;  // PIR sensörünün başlangıçta hareket algılamadığı varsayılır. 
int deger = 0;       // deger değişkenine başlangıç değeri 0 atanır. 
int buzzerpin = 10;  //Buzzer pini tanımlanır. 

void setup() {
pinMode(ledpin, OUTPUT);   // LED pini çıkış olarak tanımlanır. 
pinMode(sensorpin, INPUT); // Sensör pini giriş olarak tanımlanır. 
pinMode(buzzerpin, OUTPUT); //Buzzer pini çıkış olarak tanımlanır. 
Serial.begin(9600);   // Seri veri girişi başlatılır. 
}

void loop(){
deger = digitalRead(sensorpin);  // sensörden okunan değer değişkene atanır. 
if (deger == HIGH) {            // Eğer hareket algılanıp değer HIGH olursa...
digitalWrite(ledpin, HIGH);  // LED yanar.
Serial.println("Hareket algılandı!"); //seriport ekranına "Hareket Algılandı" yazar.
tone(buzzerpin, 440); //Buzzer ses çıkarmaya başlar.
delay(150);
}  
else  if (deger == LOW) { // Eğer hareket olmazsa...
digitalWrite(ledpin, LOW); // LED söner
noTone(buzzerpin); //buzzer susar
delay(300);  
// Seriport ekranına "Hareket yok!" yazar. 
Serial.println("Hareket yok!");
}
}



