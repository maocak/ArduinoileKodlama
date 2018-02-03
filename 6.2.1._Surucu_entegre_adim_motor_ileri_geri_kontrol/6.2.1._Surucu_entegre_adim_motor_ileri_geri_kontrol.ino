#include <Stepper.h>

#define adim 32  // Bu sayı motorun her dönüşünde atacağı adıma uygun olarak değiştirilir. 
//Adım motorun bir tam turu 32 parçaya(step) bölündü, dolayısıyla her bir adımda motor 360/32=11,25 derece dönecek
// Adım motor kütüphanesi pin 8-11 arasında bağlanılarak başlatılır. bağlantı 8-10-9-11 şeklinde olmalıdır. Yoksa motor yanlış döner. 
Stepper motor(adim, 8, 10, 9, 11);

void setup() {
// motor hızı 400rpm olarak ayarlanır. 
motor.setSpeed(400);
}

void loop() {
// bir yönde motor 1024 dönüş adımı yapar. (180 derece)
motor.step(1024);
delay(500);  //yarım saniye bekler. 
// Ters yönde motor 1024 dönüş adımı yapar. 
motor.step(-1024);
delay(500);  //yarım saniye bekler. 
}

