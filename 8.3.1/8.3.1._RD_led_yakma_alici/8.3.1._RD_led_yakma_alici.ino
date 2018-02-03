#define alicipin A5  //RF alıcı pini A5 olarak tanımlanır. 
#define ledpin 7  //LED pini tanımlanır. 

unsigned int deger = 0;   // değer değişkenine ilk değeri 0 atanır. 
const unsigned int ustesikdeger= 70;  //üst eşik değeri 70 olarak atanır. 
const unsigned int altesikdeger = 50;  //alt eşik değeri 50 olarak atanır. 

void setup(){
pinMode(ledpin, OUTPUT); //LED pini çıkış olarak tanımlanır. 
Serial.begin(9600); //Seri veri iletişimi başlatılır. 
}

void loop(){
deger=analogRead(alicipin); //vericiden gelen sinyal değeri A5 analog girişten okunur ve deger değişkenine atanır. 
Serial.println(deger); //deger değişkeni seri port ekranına yazdırılır. 
if(deger>ustesikdeger){ //eğer A5ten okunan değer 70ten büyükse LED söner. 
digitalWrite(ledpin, LOW);   //Vericiden LOW seviyede sinyal alınınca,LED söner
delay(50); //Alıcının LEDi söndür.
}
if(deger<altesikdeger){ //okunan değer 50 ten küçükse LED söner. 
digitalWrite(ledpin, HIGH);   //Vericiden HIGH seviyede sinyal alınınca, LED yanar. 
delay(50);
}
}

