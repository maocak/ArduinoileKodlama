int buzzerpin = 3; //buzzer pini tanımlanır
int notasayisi = 7; //notasayısı isimli bir değişken tanımlanır
 
int notalar[] = {494,  330, 349, 392,  294,  349, 330, 330};
//int notalar[] = {261,  294, 330, 349,  392,  440, 494, 523}; //notalar isimli 7 elemanlı bir dizi oluşturulur
 //                Do    Re   Mi   Fa    Sol   La   Si   Do(ince) Notalara karşılık gelen frekans değerleri dizi elemanı olarak atanır. 
void setup()
{
Serial.begin(9600);  //Seri veri girişi başlatılır. 
}

void loop()
{
for (int i = 0; i <= notasayisi; i++) //Baştan sona doğru döngü başlatılır. 
{
tone(buzzerpin, notalar[i]); // Notalar Do'dan İnce Do'ya kadar çalar. 
Serial.println(notalar[i]);  //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(750); //Her nota arasında 750 msn bekleme süresi vardır. 
}
noTone(buzzerpin); //Baştan sonra notalar çalması durdurulur.
delay(1000); //1sn beklenir.
{
for (int i = notasayisi; i >= 0; i--)//Notaların sondan başa geri gitmesi için 2. döngü kullanılır. 
{
tone(buzzerpin, notalar[i]); //Sondan başa doğru İnce Do'dan Do'ya kadar notalar çalar. 
Serial.println(notalar[i]); //Çalan notaların frekans değerleri ekrana yazdırılır. 
delay(750); //Her nota arasında 750 msn bekleme süresi vardır. 
}      
noTone(buzzerpin); //Sondan başa notaların çalması durdurulur. 
delay(1000);// 1 sn beklenir. 
}
}
