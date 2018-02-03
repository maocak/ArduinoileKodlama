#include <IRremote.h> //kütüphane kodu eklenir. 
int kiziotesiIR_pin = 11; //IR alıcının pin numarası atanır. 

IRrecv iralici(kiziotesiIR_pin); //IR alıcı nesnesi oluşturulur. 
decode_results sonuclar; //decode_results sınıfından sonuclar isimli bir nesne oluşturulur. 
//Bu nesne iralici tarafından kullanılacak olup, bilgileri decode etmeye yarar.

void setup()
{
Serial.begin(9600); //seri veri iletişimi başlatılır. 
iralici.enableIRIn(); // Alıcı başlatılır. 
}
void loop() {
if (iralici.decode(&sonuclar)) { //eğer kumandada bir tuşa basılırsa kod çalışır ve... 
Serial.println(sonuclar.value, HEX);  //heksedecimal olarak seri port ekranına yazdırılır. 
iralici.resume(); // bir sonraki değer seri port ekranına yazdırılır. 
}
delay(100); //
}

