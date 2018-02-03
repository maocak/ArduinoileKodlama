const int vericipin = 4;  //verici pin numarası atanır.   
    
void setup(){
Serial.begin(9600); //seri veri iletişimi başlatılır. 
pinMode(vericipin, OUTPUT); //verici pini çıkış olarak tanımlanır. 
pinMode(2, INPUT); // buton pini çıkış olarak tanımlanır.  
pinMode(10, OUTPUT);// LED pini çıkış olarak tanımlanır.     
}

void loop(){
Serial.println(digitalRead(2)); //buton pininden elde edilen değer seri port ekranına yazdırılır. 
if (digitalRead(2)==HIGH){ // Butona basıldığında... 
digitalWrite(10, HIGH);  // LED yanar.
digitalWrite(vericipin, HIGH);  //verici HIGH seviyede sinyal üretir. 
}
if (digitalRead(2)==LOW){ //buton basılı değilken...
digitalWrite(10, LOW); // LED söner.
digitalWrite(vericipin, LOW); //verici LOW seviyede sinyal üretir.
}
}

