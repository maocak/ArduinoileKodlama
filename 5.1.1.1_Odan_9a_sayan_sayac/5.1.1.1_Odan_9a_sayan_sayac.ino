void setup() {               
pinMode(7, OUTPUT); //7 bölümlü LED göstergede "A" kısmı
pinMode(6, OUTPUT); //7 bölümlü LED göstergede "B" kısmı
pinMode(4, OUTPUT); //7 bölümlü LED göstergede "C" kısmı
pinMode(2, OUTPUT); //7 bölümlü LED göstergede "D" kısmı
pinMode(11, OUTPUT); //7 bölümlü LED göstergede "E" kısmı
pinMode(9, OUTPUT); //7 bölümlü LED göstergede "F" kısmı
pinMode(10, OUTPUT); //7 bölümlü LED göstergede "G" kısmı
pinMode(12, OUTPUT); //7 bölümlü LED göstergede "DP" kısmı (Nokta kısmı)

}

void loop() {
 
//Sadece "nokta" yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 1);
digitalWrite(12, 0);
delay(1000);
// Hiçbir şey yazmaz. 
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "0" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "1" Sayısını yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "2" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 1);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "3" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "4" Sayısını yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 1);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);
 
// "5" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 1);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);
 
// "6" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "7" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "8" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);
 
// "9" Sayısını yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11,1);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);
 
}
