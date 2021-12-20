int sayac=0; //sayaç değeri olarak 0 atanır. 
int sensorpin=A5; //sensör pini olarak A0 tanımlanır. 
int mindeger=0; //minimum değere 0 atanır. 
int maksdeger=1023;  //maksimum değere 1023 atanır. 

void setup()   {

//2 segmentin pin uçları çıkış olarak atanır. 
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}
void loop()
{
int analogdeger = analogRead(sensorpin); 
analogdeger = map(analogdeger, mindeger, maksdeger, 50,255); //0-1023 arası analog değer 50-255 arası değere çevrilir.

//  Birler basamağında 0 yazar
digitalWrite(A0, LOW);  
digitalWrite(A1, LOW);  
digitalWrite(2, LOW);  
digitalWrite(3, LOW);  
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
 
delay(analogdeger); //potdan okunan değere göre sayma hızı ayarlanır.

//  Birler basamağında 1 yazar 
digitalWrite(A0,HIGH);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);  
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);  
delay(analogdeger);

//  Birler basamağında 2 yazar 
digitalWrite(A0,LOW);  
digitalWrite(A1,LOW);
digitalWrite(2, HIGH);
digitalWrite(3, LOW);  
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);  
delay(analogdeger);

//  Birler basamağında 3 yazar 
digitalWrite(A0,LOW);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);  
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);  
delay(analogdeger);

//  Birler basamağında 4 yazar 
digitalWrite(A0,HIGH);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);  
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW); 
delay(analogdeger);

//  Birler basamağında 5 yazar 
digitalWrite(A0,LOW);  
digitalWrite(A1,HIGH);
digitalWrite(2, LOW);
digitalWrite(3, LOW);  
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);  
delay(analogdeger);

//  Birler basamağında 6 yazar 
digitalWrite(A0,LOW);  
digitalWrite(A1,HIGH);
digitalWrite(2, LOW);
digitalWrite(3, LOW);  
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);  
delay(analogdeger);

//  Birler basamağında 7 yazar
digitalWrite(A0,LOW);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, HIGH);  
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);  
delay(analogdeger);

//  Birler basamağında 8 yazar
digitalWrite(A0,LOW);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);  
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);  
delay(analogdeger);

//  Birler basamağında 9 yazar 
digitalWrite(A0,LOW);  
digitalWrite(A1,LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);  
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);  
delay(analogdeger);

sayac++; //sayaç 1 artırılır

if (sayac == 1){  // sayaç 1 olduğunda 10lar basamağında 1 yazar
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
}
 
if (sayac == 2){      // sayaç 2 olduğunda 10lar basamağında 2 yazar
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
}
if (sayac == 3){      // sayaç 3 olduğunda 10lar basamağında 3 yazar
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, LOW);
}
if (sayac == 4){      // sayaç 4 olduğunda 10lar basamağında 4 yazar
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (sayac == 5){      // sayaç 5 olduğunda 10lar basamağında 5 yazar
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (sayac == 6){      // sayaç 6 olduğunda 10lar basamağında 6 yazar
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (sayac == 7){      // sayaç 7 olduğunda 10lar basamağında 7 yazar
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
}
if (sayac == 8){      // sayaç 8 olduğunda 10lar basamağında 8 yazar
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (sayac == 9){      // sayaç 9 olduğunda 10lar basamağında 9 yazar
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}
if (sayac == 10){      // sayaç 10 olduğunda onlar basamağını kontrol eden gösterge LEDleri //sönerek başa döner
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
sayac = 0;   // sayaca sıfır atanarak  sayma işlemi başa döner
}
}
