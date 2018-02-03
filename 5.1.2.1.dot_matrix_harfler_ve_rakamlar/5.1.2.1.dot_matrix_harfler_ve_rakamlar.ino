#include <MaxMatrix.h> //kullanılacak kütüphane çağrılır.
int DIN = 12;   // MAX7219 entegrenin DIN pini tanımlanır.
int CS =  11;    // MAX7219 entegrenin CS pini tanımlanır.
int CLK = 10;   // MAX7219 entegrenin CLK pini tanımlanır.

int entegresayi = 1;

MaxMatrix dotmatriks(DIN, CS, CLK, entegresayi); //kaç adet MAX7219 kullanılacağı ve pinleri
//tanımlar.(bu deneyde 1 adet dotmatriks isminde bir entegre tanımlanmaktadır)
// A harfi
char A[] = {5, 8,
            B01111110,
            B00010001,
            B00010001,
            B01111110,
            B00000000,
           };
//B harfi
char B[] = {5, 8,
            B01111111,
            B01001001,
            B01001001,
            B00110110,
            B00000000,
           };
//C harfi
char C[] = {5, 8,
            B00111110, 
            B01000001, 
            B01000001, 
            B00100010, 
            B00000000,
           };

//D harfi
char D[] = {5, 8,
            B01111111, 
            B01000001, 
            B01000001, 
            B00111110, 
            B00000000,
           };
//E harfi
char E[] = {5, 8,
            B01111111, 
            B01001001, 
            B01001001, 
            B01000001, 
            B00000000,
           };
//F harfi
char F[] = {5, 8,
            B01111111, 
            B00001001, 
            B00001001, 
            B00000001, 
            B00000000,
           };
 //G harfi
 char G[] = {5, 8,
            B00111110, 
            B01000001, 
            B01001001, 
            B01111010, 
            B00000000,
           }; 
//H harfi
char H[] = {5, 8,
            B01111111, 
            B00001000, 
            B00001000, 
            B01111111, 
            B00000000,
           };  
//I harfi
char I[] = {5, 8,
            B01000001, 
            B01111111, 
            B01000001, 
            B00000000, 
            B00000000,
           };
 
 //J harfi
 char J[] = {5, 8,
            B00110000, 
            B01000000, 
            B01000001, 
            B00111111, 
            B00000001,
           };
  
//K harfi
char K[] = {5, 8,
            B01111111, 
            B00001000, 
            B00010100, 
            B01100011, 
            B00000000,
           };  
           
//L harfi
char L[] = {5, 8,
            B01111111, 
            B01000000, 
            B01000000, 
            B01000000, 
            B00000000,
           }; 
           
//M harfi
char M[] = {5, 8,
            B01111111, 
            B00000010, 
            B00001100, 
            B00000010, 
            B01111111,
           };           
  

//N harfi
char N[] = {5, 8,
            B01111111, 
            B00000100, 
            B00001000, 
            B00010000, 
            B01111111,
           }; 
           
//O harfi
char O[] = {5, 8,
            B00111110, 
            B01000001, 
            B01000001, 
            B00111110, 
            B00000000,
           }; 
            
//P harfi
char P[] = {5, 8,
            B01111111, 
            B00001001, 
            B00001001, 
            B00000110, 
            B00000000,
           };
  
//R harfi
char R[] = {5, 8,
            B01111111, 
            B00001001, 
            B00001001, 
            B01110110, 
            B00000000,
           };  

//S harfi
char S[] = {5, 8,
            B01000110, 
            B01001001, 
            B01001001, 
            B00110010, 
            B00000000,
           };            

//T harfi
char T[] = {5, 8,
            B00000001, 
            B00000001, 
            B01111111, 
            B00000001, 
            B00000001,
           };
//U harfi
char U[] = {5, 8,
            B00111111, 
            B01000000, 
            B01000000, 
            B00111111, 
            B00000000,
           };           
//V harfi
char V[] = {5, 8,
            B00001111, 
            B00110000, 
            B01000000, 
            B00110000, 
            B00001111,
           };  

//Y harfi
char Y[] = {5, 8,
            B00000111, 
            B00001000, 
            B01110000, 
            B00001000, 
            B00000111,
           };  

//Z harfi
char Z[] = {5, 8,
            B01100001, 
            B01010001, 
            B01001001, 
            B01000111, 
            B00000000,
           }; 

//0 rakamı
char sifir[] = {5, 8,
            B00111110, 
            B01000001, 
            B01000001, 
            B00111110, 
            B00000000,
           };

//1 rakamı
char bir[] = {5, 8,
            B01000010, 
            B01111111, 
            B01000000, 
            B00000000, 
            B00000000,
           };
           
 //2 rakamı
 char iki[] = {5, 8,
            B01100010, 
            B01010001, 
            B01001001, 
            B01000110, 
            B00000000,
           };
 //3 rakamı          
  char uc[] = {5, 8,
            B00100010, 
            B01000001, 
            B01001001, 
            B00110110, 
            B00000000,
           };          
  //4 rakamı
  char dort[] = {5, 8,
            B00011000, 
            B00010100, 
            B00010010, 
            B01111111, 
            B00000000,
           };
  //5 rakamı         
  char bes[] = {5, 8,
            B00100111, 
            B01000101, 
            B01000101, 
            B00111001, 
            B00000000,
           }; 
//6 rakamı
  char alti[] = {5, 8,
            B00111110, 
            B01001001, 
            B01001001, 
            B00110000, 
            B00000000,
           };           
  //7 rakamı         
   char yedi[] = {5, 8,
          B01100001, 
          B00010001, 
          B00001001, 
          B00000111, 
          B00000000,
           };           
  //8 rakamı          
  char sekiz[] = {5, 8,
          B00110110, 
          B01001001, 
          B01001001, 
          B00110110, 
          B00000000,
           };  
  //9 rakamı
  char dokuz[] = {5, 8,
          B00000110, 
          B01001001, 
          B01001001, 
          B00111110, 
          B00000000,
           }; 
  
void setup() {
dotmatriks.init(); // MAX7219 başlatılır.
dotmatriks.setIntensity(8); // led matriksin ışık şiddeti ayarlanır ( 0 ile 15 arasında bir değer olabilir)
}

void loop() {
dotmatriks.clear(); //Gösterge temizlenir
// x ve y pozisyonunda gösterilecek karakter belirlenir. 
dotmatriks.writeSprite(2, 0, A); //sol üst köşeden başlayarak (2,0) koordinatından itibaren karakter gösterimi gerçekleştirilir.
delay(1000); //Her karakter geçişinde 1 saniye ara verilir. 
dotmatriks.writeSprite(2, 0, B);
delay(1000);
dotmatriks.writeSprite(2, 0, C);
delay(1000);
dotmatriks.writeSprite(2, 0, D);
delay(1000);
dotmatriks.writeSprite(2, 0, E);
delay(1000);
dotmatriks.writeSprite(2, 0, F);
delay(1000);
dotmatriks.writeSprite(2, 0, G);
delay(1000);
dotmatriks.writeSprite(2, 0, H);
delay(1000);
dotmatriks.writeSprite(2, 0, I);
delay(1000);
dotmatriks.writeSprite(2, 0, J);
delay(1000);
dotmatriks.writeSprite(2, 0, K);
delay(1000);
dotmatriks.writeSprite(2, 0, L);
delay(1000);
dotmatriks.writeSprite(2, 0, M);
delay(1000);
dotmatriks.writeSprite(2, 0, N);
delay(1000);
dotmatriks.writeSprite(2, 0, O);
delay(1000);
dotmatriks.writeSprite(2, 0, P);
delay(1000);
dotmatriks.writeSprite(2, 0, R);
delay(1000);
dotmatriks.writeSprite(2, 0, S);
delay(1000);
dotmatriks.writeSprite(2, 0, T);
delay(1000);
dotmatriks.writeSprite(2, 0, U);
delay(1000);
dotmatriks.writeSprite(2, 0, V);
delay(1000);
dotmatriks.writeSprite(2, 0, Y);
delay(1000);
dotmatriks.writeSprite(2, 0, Z);
delay(1000);
dotmatriks.writeSprite(2, 0, sifir);
delay(1000);
dotmatriks.writeSprite(2, 0, bir);
delay(1000);
dotmatriks.writeSprite(2, 0, iki);
delay(1000);
dotmatriks.writeSprite(2, 0, uc);
delay(1000);
dotmatriks.writeSprite(2, 0, dort);
delay(1000);
dotmatriks.writeSprite(2, 0, bes);
delay(1000);
dotmatriks.writeSprite(2, 0, alti);
delay(1000);
dotmatriks.writeSprite(2, 0, yedi);
delay(1000);
dotmatriks.writeSprite(2, 0, sekiz);
delay(1000);
dotmatriks.writeSprite(2, 0, dokuz);
delay(1000);
dotmatriks.clear();//Gösterge tekrar temizlenir.
}
