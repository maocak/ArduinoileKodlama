#include <Servo.h>  //Servo motor kütüphanesi eklenir

Servo servomotor;  // //bağlanılan servo motor için bir servo motor nesnesi oluşturulur
int aci = 0;    //aci ilk değer 0 atanır.

void setup() {
servomotor.attach(3);  // 3 nolu dijital pine servomotor data pini bağlanır.
}

void loop() {
for (aci = 0; aci <= 180; aci += 1) { // 0 dan 180 dereceye gider
// 1 er derecelik adımlarla
servomotor.write(aci);              // aci değişkeninin aldığı değere servo motorun gitmesini sağlar. 
delay(15);                       // 180 dereceye ulaşınca 15 milisaniye bekler 
}
for (aci = 180; aci >= 0; aci -= 1) { // 180 dereceden 0 dereceye gider
servomotor.write(aci);              // aci değişkeninin aldığı değere servo motorun gitmesini sağlar.
delay(15);                       // 0 dereceye ulaşınca 15 milisaniye bekler 
}
}

