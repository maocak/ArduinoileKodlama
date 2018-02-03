float sicaklikC;  //sicaklikC isminde bir değişken tanımlanır. 
int sicaklikD; //sicaklikD isminde bir değişken tanımlanır. 
int LM35pin = 0; //LM35 sensör pini tanımlanır. 
int ledpin = 13; //LED pini tanımlanır.  

void setup()
{
Serial.begin(9600); //Seri veri alışverişi başlatılır. 
pinMode(2, OUTPUT); //2 adet 7 bölümlü LED gösterge pin uçları çıkış olarak tanımlanır. 
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT); // LED pin ucu çıkış olarak tanımlanır. 
pinMode(A2, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A5, OUTPUT);

}

void loop()
{
sicaklikC = analogRead(LM35pin); //LM35 den okunan analog değer sicaklikC isminde değişkene atanır. 
sicaklikC = (sicaklikC/1023) *5000; //analog değer mV cinsinden değere dönüştürülür. 
sicaklikC= sicaklikC/10; //mV cinsinden değer, santigrad cinsinden değere dönüştürülür. 
sicaklikD = (int)sicaklikC; //sicaklikC değeri tamsayıya dönüştürülür.
Serial.println(sicaklikD);  //Sıcaklık değeri tamsayı olarak seriport ekranına yazdırılır. 
  
delay(10);
// Sıcaklık ölçümü her 1 saniye gerçekleşir ve tüm pin uçları HIGH ile 0 yapılarak bir sonraki okumaya hazır hale getirilir. 
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(A2, HIGH);
digitalWrite(A3, HIGH);
digitalWrite(A4, HIGH);
digitalWrite(A5, HIGH);
   
if (sicaklikD == 0)  // 0-99 arasındaki sıcaklık değerlerine göre 2 göstergeye ilgili rakamların yazdırılması için fonksiyonlar çağrılır. 
{
Asifir(); 
}
if (sicaklikD == 1)
{
Abir();
}
if(sicaklikD == 2)
{
Aiki();
}
if(sicaklikD == 3)
{
Auc();
}
if(sicaklikD == 4)
{
Adort();
}
if(sicaklikD == 5)
{
Abes();
}
if(sicaklikD == 6)
{
Aalti();
}
if(sicaklikD == 7)
{
Ayedi();
}
if(sicaklikD == 8)
{
Asekiz();
}
if(sicaklikD == 9)
{
Adokuz();
}
if(sicaklikD == 10)
{
Abir();
Bsifir();
}
if(sicaklikD == 11)
{
Abir();
Bbir();
}
if(sicaklikD == 12)
{
Abir();
Biki();
}
if(sicaklikD == 13)
{
Abir();
Buc();
}
if(sicaklikD == 14)
{
Abir();
Bdort();
}
if(sicaklikD == 15)
{
Abir();
Bbes();
}
if(sicaklikD == 16)
{
Abir();
Balti();
}
if(sicaklikD == 17)
{
Abir();
Byedi();
}
if(sicaklikD == 18)
{
Abir();
Bsekiz();
}
if(sicaklikD == 19)
{
Abir();
Bdokuz();
}
if(sicaklikD == 20)
{
Aiki();
Bsifir();
}
if(sicaklikD == 21)
{
Aiki();
Bbir();
}
if(sicaklikD == 22)
{
Aiki();
Biki();
}
if(sicaklikD == 23)
{
Aiki();
Buc();
}
if(sicaklikD == 24)
{
Aiki();
Bdort();
}
if(sicaklikD == 25)
{
Aiki();
Bbes();
}
if(sicaklikD == 26)
{
Aiki();
Balti();
}
if(sicaklikD == 27)
{
Aiki();
Byedi();
}
if(sicaklikD == 28)
{
Aiki();
Bsekiz();
}
if(sicaklikD == 29)
{
Aiki();
Bdokuz();
}
if(sicaklikD == 30)
{
Auc();
Bsifir();
}
if(sicaklikD == 31)
{
Auc();
Bbir();
}
if(sicaklikD == 32)
{
Auc();
Biki();
}
if(sicaklikD == 33)
{
Auc();
Buc();
}
if(sicaklikD == 34)
{
Auc();
Bdort();
}
if(sicaklikD == 35)
{
Auc();
Bbes();
}
if(sicaklikD == 36)
{
Auc();
Balti();
}
if(sicaklikD == 37)
{
Auc();
Byedi();
}
if(sicaklikD == 38)
{
Auc();
Bsekiz();
}
if(sicaklikD == 39)
{
Auc();
Bdokuz();
}
if(sicaklikD == 40)
{
Adort();
Bsifir();
}
if(sicaklikD == 41)
{
Adort();
Bbir();
}
if(sicaklikD == 42)
{
Adort();
Biki();
}
if(sicaklikD == 43)
{
Adort();
Buc();
}
if(sicaklikD == 44)
{
Adort();
Bdort();
}
if(sicaklikD == 45)
{
Adort();
Bbes();
}
if(sicaklikD == 46)
{
Adort();
Balti();
}
 if(sicaklikD == 47)
{
Adort();
Byedi();
}
if(sicaklikD == 48)
{
Adort();
Bsekiz();
}
if(sicaklikD == 49)
{
Adort();
Bdokuz();
}
if(sicaklikD == 50)
{
Abes();
Bsifir();
}
if(sicaklikD == 51)
{
Abes();
Bbir();
}
if(sicaklikD == 52)
{
Abes();
Biki();
}
if(sicaklikD == 53)
{
Abes();
Buc();
}
if(sicaklikD == 54)
{
Abes();
Bdort();
}
if(sicaklikD == 55)
{
Abes();
Bbes();
}
if(sicaklikD == 56)
{
Abes();
Balti();
}
if(sicaklikD == 57)
{
Abes();
Byedi();
}
if(sicaklikD == 58)
{
Abes();
Bsekiz();
}
if(sicaklikD == 59)
{
Abes();
Bdokuz();
}
if(sicaklikD == 60)
{
Aalti();
Bsifir();
}
if(sicaklikD == 61)
{
Aalti();
Bbir();
}
if(sicaklikD == 62)
{
Aalti();
Biki();
}
if(sicaklikD == 63)
{
Aalti();
Buc();
}
if(sicaklikD == 64)
{
Aalti();
Bdort();
}
if(sicaklikD == 65)
{
Aalti();
Bbes();
}
if(sicaklikD == 66)
{
Aalti();
Balti();
}
if(sicaklikD == 67)
{
Aalti();
Byedi();
}
if(sicaklikD == 68)
{
Aalti();
Bsekiz();
}
if(sicaklikD == 69)
{
Aalti();
Bdokuz();
}
if(sicaklikD == 70)
{
Ayedi();
Bsifir();
}
if(sicaklikD == 61)
{
Aalti();
Bbir();
}
if(sicaklikD == 62)
{
Aalti();
Biki();
}
if(sicaklikD == 63)
{
Aalti();
Buc();
}
if(sicaklikD == 64)
{
Aalti();
Bdort();
}
if(sicaklikD == 65)
{
Aalti();
Bbes();
}
if(sicaklikD == 66)
{
Aalti();
Balti();
}
if(sicaklikD == 67)
{
Aalti();
Byedi();
}
if(sicaklikD == 68)
{
Aalti();
Bsekiz();
}
if(sicaklikD == 69)
{
Aalti();
Bdokuz();
}
if(sicaklikD == 70)
{
Ayedi();
Bsifir();
}
if(sicaklikD == 71)
{
Ayedi();
Bbir();
}
if(sicaklikD == 72)
{
Ayedi();
Biki();
}
if(sicaklikD == 73)
{
Ayedi();
Buc();
}
if(sicaklikD == 74)
{
Ayedi();
Bdort();
}
if(sicaklikD == 75)
{
Ayedi();
Bbes();
}
if(sicaklikD == 76)
{
Ayedi();
Balti();
}
if(sicaklikD == 77)
{
Ayedi();
Byedi();
}
if(sicaklikD == 78)
{
Ayedi();
Bsekiz();
}
if(sicaklikD == 79)
{
Ayedi();
Bdokuz();
}
if(sicaklikD == 80)
{
Asekiz();
Bsifir();
}
if(sicaklikD == 81)
{
Asekiz();
Bbir();
  }
if(sicaklikD == 82)
{
Asekiz();
Biki();
}
if(sicaklikD == 83)
{
Asekiz();
Buc();
}
if(sicaklikD == 84)
{
Asekiz();
Bdort();
}
if(sicaklikD == 85)
{
Asekiz();
Bbes();
}
if(sicaklikD == 86)
{
Asekiz();
Balti();
}
if(sicaklikD == 87)
{
Asekiz();
Byedi();
}
if(sicaklikD == 88)
{
Asekiz();
Bsekiz();
}
if(sicaklikD == 89)
{
Asekiz();
Bdokuz();
}

if(sicaklikD == 90)
{
Adokuz();
Bsifir();
}
if(sicaklikD == 91)
{
Adokuz();
Bbir();
}
if(sicaklikD == 92)
{
Adokuz();
Biki();
}
if(sicaklikD == 93)
{
Adokuz();
Buc();
}
if(sicaklikD == 94)
{
Adokuz();
Bdort();
}
if(sicaklikD == 95)
{
Adokuz();
Bbes();
}
if(sicaklikD == 96)
{
Adokuz();
Balti();
}
if(sicaklikD == 97)
{
Adokuz();
Byedi();
}
if(sicaklikD == 98)
{
Adokuz();
Bsekiz();
}
if(sicaklikD == 99)
{
Adokuz();
Bdokuz();
} 
if(sicaklikD > 99) //Eğer sıcaklık değeri 99 derecenin üstüne çıkarsa kırmızı LED yanıp sönmeye başlar. 
{
digitalWrite(13, HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
}
  
delay(1000); //Saniyede bir kere okuma yapılır. 
 
}
//Göstergelere sayıların yazılması için fonksiyonlar tanımlanır.
void Asifir()  //1.gösterge 0 rakamı
{
digitalWrite(2, LOW);
digitalWrite(12, LOW);
digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
digitalWrite(3, LOW);
}

void Abir() //1.gösterge 1 rakamı
{
digitalWrite(12, LOW);
digitalWrite(7, LOW);
}

void Aiki() // 1.gösterge 2 rakamı
{
digitalWrite(2, LOW);
digitalWrite(12, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}

void Auc()  //1.gösterge 3 rakamı
{
digitalWrite(2,LOW);
digitalWrite(12,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
}

void Adort() //1.gösterge 4 rakamı
{
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(12,LOW);
digitalWrite(7,LOW);
}

void Abes() //1.gösterge 5 rakamı
{
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);

}

void Aalti()//1.gösterge 6 rakamı
{
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
}

void Ayedi() //1.gösterge 7 rakamı
{
digitalWrite(2,LOW);
digitalWrite(12,LOW);
digitalWrite(7,LOW);
}

void Asekiz()//1.gösterge 8 rakamı
{
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(12,LOW);
digitalWrite(5,LOW);
digitalWrite(7,LOW);
digitalWrite(6,LOW);
}

void Adokuz()  //1.gösterge 9 rakamı
{
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(12,LOW);
digitalWrite(7,LOW);
}
void Bsifir() //2.gösterge 0 rakamı
{
digitalWrite(A4, LOW);
digitalWrite(A5, LOW);
digitalWrite(A3, LOW);
digitalWrite(9, LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
}
void Bbir()//2.gösterge 1 rakamı
{
digitalWrite(A5, LOW);
digitalWrite(11, LOW);
}

void Biki()//2.gösterge 2 rakamı
{
digitalWrite(A4, LOW);
digitalWrite(A5, LOW);
digitalWrite(A2, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
}

void Buc() //2.gösterge 3 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A5,LOW);
digitalWrite(A2,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}

void Bdort()//2.gösterge 4 rakamı
{
digitalWrite(A3,LOW);
digitalWrite(A2,LOW);
digitalWrite(A5,LOW);
digitalWrite(11,LOW);
}

void Bbes() //2.gösterge 5 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A3,LOW);
digitalWrite(A2,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);

}

void Balti() //2.gösterge 6 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A3,LOW);
digitalWrite(A2,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
}

void Byedi() //2.gösterge 7 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A5,LOW);
digitalWrite(11,LOW);
}

void Bsekiz()//2.gösterge 8 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A3,LOW);
digitalWrite(A2,LOW);
digitalWrite(A5,LOW);
digitalWrite(9,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}

void Bdokuz() //2.gösterge 9 rakamı
{
digitalWrite(A4,LOW);
digitalWrite(A3,LOW);
digitalWrite(A2,LOW);
digitalWrite(A5,LOW);
digitalWrite(11,LOW);
}
