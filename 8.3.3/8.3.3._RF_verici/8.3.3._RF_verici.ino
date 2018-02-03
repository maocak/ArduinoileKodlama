#include <VirtualWire.h> //Kütüphane, koda eklenir. 
char veri[100]; //100 karakterlik veri isminde bir dizi tanımlanır. 
int i=0;
void setup()
{
Serial.begin(9600); //seri veri iletişimi başlatılır.
vw_setup(2000); //kütüphane başlatılır. 2000 saniyede yollanacak bit sayısını belirtir.
Serial.print("LCD ekrana yazdırılıcak veriyi giriniz!"); //seri port ekranından veri girişi yapılması istenir. 
}
void loop()
{
if( Serial.available() > 0)  //eğer veri girişi yapılırsa...
{
veri[i] = Serial.read(); //girilen verinin her bir karakteri dizinin elemanlarına olarak aktarılır.
i++;
}
if( veri[i] == '\0') //eğer verinin sonuna ulaşılırsa(yani son karakter \0 okunursa)...
{
i=0;
vw_send((byte *)veri, strlen(veri)); //veri baytlar halinde alıcıya yollanır. strlen veri uzunluğu gösterir.
delay(400);
}
}
