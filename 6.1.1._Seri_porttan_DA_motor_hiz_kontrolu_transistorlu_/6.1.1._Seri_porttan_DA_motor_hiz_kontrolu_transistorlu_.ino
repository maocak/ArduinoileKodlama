int DAmotorpin = 3; //DA motor pin numarası tanımlanır. 
     
void setup() 
{ 
pinMode(DAmotorpin, OUTPUT);  //DA motor pini çıkış olarak tanımlanır. 
Serial.begin(9600);  //Seri veri iletişimi başlatılır. 
while (! Serial); //kullanılacak portun açık olup olmadığı kontrol edilerek hazır hale getirilir. 
//(bunun için USB kablosunun Arduino UNO kartına takılı olması gerekir)
Serial.println("0-255 arası sayı giriniz"); //seri porttan sayı girilmesi için yazı yazar.
} 
     
void loop() 
{ 
if (Serial.available()) //seri portan girilen karakter okunur ve arabellekte hazır hale getirilir. 
{
int DAmotorhizi = Serial.parseInt(); //seri porttan girilen değer text olarak okunur ve int değişken türüne dönüştürülür. 
if (DAmotorhizi >= 0 && DAmotorhizi <= 255)  //girilen değerin 0-255 arası olması koşulla kontrol edilir. 
{
analogWrite(DAmotorpin, DAmotorhizi); //Girilen analog değere göre DA motor pinine değer yollanır ve motor hızı ayarlanır. 
}
}
} 
