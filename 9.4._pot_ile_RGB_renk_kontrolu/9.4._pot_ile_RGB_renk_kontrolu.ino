int yesilLEDpin=3; //LEDlerin pin numaraları atanır. 
int maviLEDpin=5;
int kirmiziLEDpin=6;
int potpin=5; //potun pin numarası atanır. 
int deger; //deger isimli bir değişken tanımlanır. 

void setup(){
Serial.begin(9600); //seri veri iletişimi başlatılır. 
pinMode(yesilLEDpin,OUTPUT);  //LED pinleri çıkış olarak atanır. 
pinMode(maviLEDpin,OUTPUT); 
pinMode(kirmiziLEDpin,OUTPUT); 
}

void loop(){
deger= analogRead(potpin); //pottan okunan sayı deger isimli değişkene atanır. 
Serial.println(deger);  //sayı seri port ekran yazdırılır. 
if (deger<150) {  //analog değer 150den küçükse...
analogWrite(kirmiziLEDpin,0); //kırmızı renk elde edilir. 
analogWrite(maviLEDpin,255); 
analogWrite(yesilLEDpin,255);    
} else if (deger<300) {  //analog değer 300den küçükse...
analogWrite(kirmiziLEDpin,255);  //mavi renk
analogWrite(maviLEDpin,0); 
analogWrite(yesilLEDpin,255);
} else if (deger<450) { //analog değer 450den küçükse...
analogWrite(kirmiziLEDpin,255); //yeşil renk
analogWrite(maviLEDpin,255); 
analogWrite(yesilLEDpin,0);  
} else if (deger<600) {  //analog değer 600den küçükse...
analogWrite(kirmiziLEDpin,0); //sarı renk
analogWrite(maviLEDpin,255); 
analogWrite(yesilLEDpin,0);
} else if (deger<750) {  //analog değer 750den küçükse...
analogWrite(kirmiziLEDpin,0); //mor renk
analogWrite(maviLEDpin,0); 
analogWrite(yesilLEDpin,255);  
} else if (deger<900) {  //analog değer 900den küçükse...
analogWrite(kirmiziLEDpin,255);  //turkuaz renk
analogWrite(maviLEDpin,0); 
analogWrite(yesilLEDpin,0);
}else if (deger<1024) {  //analog değer 1024den küçükse...
analogWrite(kirmiziLEDpin,0); //beyaz renk elde edilir. 
analogWrite(maviLEDpin,0); 
analogWrite(yesilLEDpin,0);
}
delay(10);
}


