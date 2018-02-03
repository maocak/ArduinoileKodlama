int ledpin = 13 ;// LED pini tanımlanır. 
int sensorpin = 3; // Civalı sensör pini tanımlanır. 
int deger=0; ;// deger değişkenine başlangıç değeri 0 atanır. 

void setup ()
{
Serial.begin(9600); //Seri veri akışı başlatılır. 
pinMode (ledpin, OUTPUT) ;// LED pini çıkış olarak tanımlanır. 
pinMode (sensorpin, INPUT); // Sensör pini giriş olarak tanımlanır. 
}

void loop ()
{
deger = digitalRead (sensorpin) ;// sensörden okunan değer(1 ya da 0) değişkene atanır. 
Serial.println(deger); //okunan değer seri port ekranına yazdırılır. 
if (deger == HIGH) // Civalı sensör HIGH değeri aldığında...
{
digitalWrite (ledpin, HIGH); //LED yanar.
Serial.println("Eğim var"); //Ekrana "Eğim var" yazar.
}
else
{
digitalWrite (ledpin, LOW);  //eğer eğim yoksa LED söner
Serial.println("Eğim yok");  //Ekrana "Eğim yok" yazar.
}
delay(250);
}
