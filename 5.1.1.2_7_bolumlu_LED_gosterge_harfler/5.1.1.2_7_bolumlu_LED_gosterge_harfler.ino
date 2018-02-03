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
// "A" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "B" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "C" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "D" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "E" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "F" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);


// "H" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "I" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "J" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 1);
digitalWrite(9, 1);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "L" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "n" küçük n harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "o" küçük o harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "P" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "r" küçük r harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 1);
digitalWrite(4, 1);
digitalWrite(2, 1);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "S" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 1);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 1);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "U" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 0);
digitalWrite(10, 1);
digitalWrite(12, 1);
delay(1000);

// "Y" harfini yazar.
digitalWrite(7, 1);
digitalWrite(6, 0);
digitalWrite(4, 0);
digitalWrite(2, 0);
digitalWrite(11, 1);
digitalWrite(9, 0);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

// "Z" harfini yazar.
digitalWrite(7, 0);
digitalWrite(6, 0);
digitalWrite(4, 1);
digitalWrite(2, 0);
digitalWrite(11, 0);
digitalWrite(9, 1);
digitalWrite(10, 0);
digitalWrite(12, 1);
delay(1000);

}
