void setup() {

pinMode(7,OUTPUT); // LED’in bağlı olduğu 7 numaralı  pin çıkış olarak belirlenir.
}

void loop() {

digitalWrite(7, HIGH); // LED yanar 
delay(1000); // 1saniye bekler
digitalWrite(7, LOW); // LED söner
delay(1000); // 1 saniye bekler
}
