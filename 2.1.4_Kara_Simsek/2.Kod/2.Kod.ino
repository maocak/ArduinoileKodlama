int led1 = 9; 
int led2 = 8;
int led3 = 7; 
int led4 = 6;
int led5 = 5; 
int led6 = 4; 
int led7 = 3; 
int led8 = 2; 

const int bekleme = 50; 
// Pin numaralarını belirleyecek 8 bitlik bir dizi 
//oluşturulur.
int pinDizi[] = {2, 3, 4, 5, 6, 7, 8, 9};

int sayac = 0;

// LED pinleri çıkış olarak ayarlanır.
void setup () 
{ 
pinMode(led1,OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(led4, OUTPUT); 
pinMode(led5, OUTPUT); 
pinMode(led6, OUTPUT); 
pinMode(led7, OUTPUT); 
pinMode(led8, OUTPUT); 
} 

// Sıfırdan 8’e doğru artarak sayan bir sayaç vasıtasıyla sırası gelen LED’i yakıp söndüren 
//döngüdür.

void loop() { 
for (sayac=0;sayac<8;sayac++) {
digitalWrite(pinDizi[sayac], HIGH);
delay(bekleme);
digitalWrite(pinDizi[sayac], LOW);
delay(bekleme);
}

//8’den 0’a geriye doğru sayaç vasıtasıyla sırası gelen LED’i yakıp söndüren döngüdür.
for (sayac=7;sayac>=0;sayac--) {
digitalWrite(pinDizi[sayac], HIGH);
delay(bekleme);
digitalWrite(pinDizi[sayac], LOW);
delay(bekleme);
}
}
