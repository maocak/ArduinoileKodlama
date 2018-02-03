#include   <Servo.h>      //Servo motor kütüphanesi eklenir
 
Servo servomotor;      //bağlanılan servo motor için bir servo motor nesnesi oluşturulur.  
                
int aci = 0;    //aci ilk değer 0 atanır. 
int pot = A0;      // pot değeri A0 olarak atanır. 

void setup() 
{ 
Serial.begin(9600); //seri veri iletişimi başlatılır. 
servomotor.attach(3);   // 3 nolu dijital pine servomotor data pini bağlanır. 
} 

void loop() 
{ 
aci = analogRead(pot);            // 0 ile 1023 arası değer A0 analog girişten okunur.  
aci = map(aci,0,1023, 0, 180);     // Okunan analog değer 0 ile 180 arasında değere dönüştürülür 
Serial.println(aci);  //seri port ekranından açı değeri okunur. 
servomotor.write(aci);                   //pot ile belirlenen aci değerine servo motorun gitmesi sağlanır.  
delay(15);             
}
