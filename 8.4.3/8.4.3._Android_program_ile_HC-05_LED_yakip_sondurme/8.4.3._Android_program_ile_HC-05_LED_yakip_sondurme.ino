int ledpin = 13; //LED pini tanımlanır. 
int durum=0;  //durum değişkenine ilk değer atanır. 

void setup(){
Serial.begin(38400);  //seri veri iletişimi başlatılır. 
pinMode(ledpin,OUTPUT); //LED pini çıkış olarak tanımlanır. 
}

void loop(){
if(Serial.available()!=0){ //Eğer seri port ekranından giriş yapılırsa...
durum= Serial.read();  //girilen değer durum adlı değişkene atanır. 
}
if (durum =='h'){  //Girilen değer eğer h ise LED yanar. 
digitalWrite(ledpin,HIGH);
}
if(durum=='l'){  //Girilen değer l ise LED söner. 
digitalWrite(ledpin,LOW);
}
}

