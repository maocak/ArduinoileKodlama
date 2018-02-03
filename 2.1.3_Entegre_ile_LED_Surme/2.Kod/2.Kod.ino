int biteyaz = 9;
int tetiklemepin= 10;
int veripin = 8;
 
byte ledler = 1;
 
void setup() 
{

pinMode(biteyaz, OUTPUT);
pinMode(veripin, OUTPUT);  
pinMode(tetiklemepin, OUTPUT);
}
 
void loop() 
{
ledler = 1;
kaydirmalikaydedici();
delay(500);
 
for (int i = 0; i < 8; i++)
{
bitSet(ledler, i);
kaydirmalikaydedici();
delay(500);
}
}
 
void  kaydirmalikaydedici()
{
digitalWrite(biteyaz, LOW);
shiftOut(veripin, tetiklemepin, LSBFIRST, ledler);
digitalWrite(biteyaz, HIGH);
}

