int ldr = A5; //A5 nolu analog pin LDR pin olarak tanımlanır
unsigned int deger=0 ; //deger değişkeninin ilk değeri 0 olarak tanımlanır.

void setup()
{
Serial.begin(9600); //seri veri giriş çıkışı başlatılır. 
pinMode (5,OUTPUT); //5,6, ve 7 nolu çıkışlar LED çıkışları olarak atanır.
pinMode (6,OUTPUT);
pinMode (7,OUTPUT);
}

void loop()
{
deger = analogRead(ldr); //LDR'den okunan değer deger değişkenine atanır. 
Serial.print("LDR ışık seviyesi analog değeri:");
Serial.println(deger); //okunan değer ekrana yazdırılır
if ( deger >250 ) //eğer okunan analog değer 250'den fazlaysa 1. led yanar
{
digitalWrite(5,HIGH);
} else{
digitalWrite(5,LOW);
}
if ( deger > 350)//eğer okunan değer 350'den fazlaysa 2. ledde yanar.
{
digitalWrite(6,HIGH);
} else {
digitalWrite(6,LOW);
}
if (deger > 560)//eğer okunan değer 560'dan fazlaysa 3. ledde yanar.
{
digitalWrite(7,HIGH);
}else {
digitalWrite(7,LOW);
}  
delay(10);               
}
