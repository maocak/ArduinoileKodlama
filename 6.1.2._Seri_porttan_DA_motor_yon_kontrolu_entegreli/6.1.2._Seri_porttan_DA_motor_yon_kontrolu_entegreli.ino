const int LEDpin_sag=2; //motor sağa dönünce yanacak ledin pini atanır. 
const int LEDpin_sol=3; //motor sola dönünce yanacak ledin pini atanır. 

const int enablepin = 4; //L293D entegrenin enable pini atanır. 
const int motorpin_sag = 5;  //motoru sağa döndüren pin atanır. 
const int motorpin_sol = 6;  //motoru sola döndüren pin atanır. 

char data; //data isminde char türünde bir değişken tanımlanır. 

void setup()
{
Serial.begin(9600);  //seri veri iletişim başlatılır. 
pinMode(LEDpin_sag,OUTPUT);  // pinler çıkış olarak tanımlanır. 
pinMode(LEDpin_sol,OUTPUT);
pinMode(motorpin_sag, OUTPUT);
pinMode(motorpin_sol, OUTPUT);
pinMode(enablepin, OUTPUT);

}

void loop()
{

if(Serial.available()>0) //seri portan girilen karakter okunur ve arabellekte hazır hale getirilir. 
{
data=Serial.read(); //okunan veri data isminde char türünden bir değişkene atanır. 
if(data=='1')  //eğer girilen veri 1 ise...  
{
digitalWrite(motorpin_sag, HIGH); //motor sağ pin ve sağ led pin HIGH duruma  geçer. Motor sağa dönmeye başlar ve sağdaki LED yanar.
digitalWrite(motorpin_sol, LOW);
digitalWrite(enablepin, HIGH);
digitalWrite(LEDpin_sag, HIGH);
digitalWrite(LEDpin_sol, LOW);
      
Serial.println("DA motor sağa dönüyor");
}
else if (data=='2')  //eğer girilen veri 2 ise...
{
digitalWrite(motorpin_sag, LOW); //motor sağ pin, sol pin, enable  pin, sol ve sağ led pin LOW duruma  geçer. Motor durur, ledler söner. 
digitalWrite(motorpin_sol, LOW);
digitalWrite(enablepin, LOW);
digitalWrite(LEDpin_sag, LOW);
digitalWrite(LEDpin_sol, LOW);
      
Serial.println("DA motor durdu ");
}
else if (data=='3')  //eğer girilen veri 3 ise...
{
digitalWrite(motorpin_sag, LOW); //motor sol pin ve sol led pin HIGH duruma  geçer. Motor sola dönmeye başlar ve soldaki LED yanar.
digitalWrite(motorpin_sol, HIGH);
digitalWrite(enablepin, HIGH);
digitalWrite(LEDpin_sag, LOW);
digitalWrite(LEDpin_sol, HIGH);
      
Serial.println("DA motor sola dönüyor");
}
}
}
