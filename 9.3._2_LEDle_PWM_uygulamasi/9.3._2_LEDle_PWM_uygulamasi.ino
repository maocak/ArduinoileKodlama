
int kirmiziLEDpin = 3;    // kırmızı LED pin numarası tanımlanır. 
int sariLEDpin = 5; // sarı LED pin numarası tanımlanır. 

void setup()  { 
} 

void loop()  { 
// min=0'den max=255 sayısına kadar 5'erli artışlarla PWM değeri artırılır.
for(int pwmdeger = 0 ; pwmdeger <= 255; pwmdeger +=5) { 
analogWrite(kirmiziLEDpin, pwmdeger); //kırmızı LEDin parlaklığı artarken...
analogWrite(sariLEDpin, (255 - pwmdeger)); //sarı LEDin parlaklığı azalır.    
delay(30);  // karartma efektini görmek için 30 milisaniye beklenir.                          
} 

//max=255'den min=0 sayısına kadar 5'erli azalışlarla PWM değeri azaltılır.
for(int pwmdeger = 255 ; pwmdeger >= 0; pwmdeger -=5) { 
analogWrite(kirmiziLEDpin, pwmdeger); //kırmızı LEDin parlaklığı azalırken...
analogWrite(sariLEDpin, (255 - pwmdeger)); //sarı LEDin parlaklığı artar.     
delay(30);  // karartma efektini görmek için 30 milisaniye beklenir.                          
} 
}

