int ledpin = 13 ;// LED pini tanımlanır
int sensorpin = 3; //  D0 dijital sensör pini tanımlanır
int deger = 0;// deger değişkenine 0 değeri atanır. 
 
void setup ()
{
pinMode (ledpin, OUTPUT) ;// ledpini çıkış olarak atanır. 
pinMode (sensorpin, INPUT) ;// D0 dijital sensör pini giriş olarak atanır. 
}
 
void loop ()
{
deger = digitalRead(sensorpin);// pin3'den okunan dijital değer deger isimli değişkene atanır. 
if (deger == HIGH) // ses sensörü bir sinyal algılandığında HIGH konumunu alır. Bu durumda LED yanar. 
{
digitalWrite (ledpin, HIGH);
delay(300); //LED'in yanması 0,3 sn sürer.
}
else
{
digitalWrite (ledpin, LOW); //ses sensörü sinyal algılamazsa LED söner.
}
}
