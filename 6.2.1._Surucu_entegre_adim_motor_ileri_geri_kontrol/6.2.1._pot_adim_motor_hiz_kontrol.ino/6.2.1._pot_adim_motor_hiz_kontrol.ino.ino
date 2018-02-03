#include <Stepper.h>
#define adim 32  //Adım motorun bir tam turu 32 parçaya(step) bölündü, dolayısıyla her bir //adımda motor 360/32=11,25 derece dönecek

// Adım motor kütüphanesi pin 8-11 arasında bağlanılarak başlatılır. 
Stepper motor(adim, 8, 10, 9, 11);

void setup() {
Serial.begin(9600); //seri veri iletişimi başlatıldı.
}

void loop() {
// A0 analog değer okunur. 
int sensorReading = analogRead(A0);
Serial.println(sensorReading); //okunan değer seri port ekrana yazdırılır. 
// eğer değer 0 dan farklı ise...
if (sensorReading > 0) {
motor.setSpeed(sensorReading);  //analog değer, motor hızı olarak atanır. 
motor.step(adim);  // motor her harekette 32 motor adımı(yaklaşık 6 derece hareket eder)
delay(10);
}
}

