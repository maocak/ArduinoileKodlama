int rolepin = 3;    //Röle pini tanımlanır.
int sensorpin = 2;   // PIR sensör pini tanımlanır. 
int deger = LOW;  // PIR sensörünün başlangıçta hareket algılamadığı varsayılır. 

void setup() {
pinMode(rolepin, OUTPUT); //Röle pini çıkış olarak atanır. 
pinMode(sensorpin, INPUT); // Sensör pini giriş olarak tanımlanır. 
Serial.begin(9600);   // Seri veri girişi başlatılır. 
}

void loop(){
deger = digitalRead(sensorpin);  // sensörden okunan değer değişkene atanır. 
if (deger == HIGH) {            // Eğer hareket algılanıp değer HIGH olursa...
digitalWrite(rolepin, HIGH);  // Röle kapanır. 1 değeri alır. Lamba yanar.
Serial.println("Hareket algılandı!"); //seriport ekranına "Hareket Algılandı" yazar.
delay(150); //Biraz beklenir.
}  
else  if (deger == LOW) { // Eğer hareket olmazsa...
digitalWrite(rolepin, LOW);  // Röle açılır. 0 değeri alır. Lamba söner.
delay(150);   //Biraz beklenir.
// Seriport ekranına "Hareket yok!" yazar. 
Serial.println("Hareket yok!");
}
}

