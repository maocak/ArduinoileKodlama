const int alicipin=A0;  //RF alıcı pini A0 olarak tanımlanır.
const int ledpin=12;  //LED pini tanımlanır.
const int buzzerpin = 8;  //buzzer pini tanımlanır. 
unsigned int deger = 0;  // değer değişkenine ilk değeri 0 atanır.
const unsigned int ustesikdeger = 100;  //üst eşik değeri 100 olarak atanır
const unsigned int altesikdeger = 70;  //alt eşik değeri 70 olarak atanır.
 
void setup(){
pinMode(ledpin, OUTPUT); //LED pini çıkış olarak tanımlanır. 
pinMode(buzzerpin, OUTPUT); //buzzer pini çıkış olarak tanımlanır. 
Serial.begin(9600);  //seri veri iletişimi başlatılır. 
}

void loop(){
deger=analogRead(alicipin); //vericiden gelen sinyal değeri A0 analog girişten okunur ve deger değişkenine atanır.  
Serial.println(deger);  //deger değişkeni seri port ekranına yazdırılır.     
     
if (deger<altesikdeger){// Eğer okunan değer 70 den küçükse...
digitalWrite(ledpin, HIGH);   //LED yanar
tone(buzzerpin,440); //buzzer ses verir. 
}
if (deger>ustesikdeger){  // Eğer okunan değer 100 den büyükse... 
digitalWrite(ledpin, LOW);   //LED söner.                               
noTone(buzzerpin); //buzzer susar.
}                         
}

