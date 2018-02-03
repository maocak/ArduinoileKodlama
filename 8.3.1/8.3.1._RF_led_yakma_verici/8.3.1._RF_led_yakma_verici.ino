#define vericipin 7  //RF verici pini tanımlanır. 
#define ledpin 12        //LED pini tanımlanır. 

void setup(){
pinMode(vericipin, OUTPUT); //verici pini çıkış olarak tanımlanır.     
pinMode(ledpin, OUTPUT);    //LED pini çıkış olarak tanımlanır. 
}

void loop(){
digitalWrite(vericipin, HIGH);   //verici pini 3 saniye boyunca HIGH seviyede sinyal yayar. 
digitalWrite(ledpin, HIGH);    // LED yanar. 
delay(3000);  //LED 3 sn boyunca yanar.  
     
digitalWrite(vericipin,LOW);  //verici pini 3 saniye boyunca LOW seviyede sinyal yayar. 
digitalWrite(ledpin, LOW);   //LED söner
delay(3000);  //LED 3 sn boyunca söner.
}


