#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       
#include <TouchScreen.h>

char *name = "TFT ekran 2.4,ID:9325";  //kalkanın durumuna göre edit edilebilir.
const int XP=6,XM=A2,YP=A1,YM=7; //ID=0x9325
const int TS_LEFT=907,TS_RT=136,TS_TOP=942,TS_BOT=139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 534);
TSPoint tp;

#define MINPRESSURE 10
#define MAXPRESSURE 1000

int16_t BOXSIZE;
int16_t PENRADIUS = 2; //daha ince ya da daha kalın yazın için 1 ya da 3 kullanın.
uint16_t ID, oldcolor, currentcolor;
uint8_t Orientation = 0;    //PORTRAIT, LANDSCAPE özelliği için 1 kullanın.


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void show_Serial(void)
{
    Serial.println(F("Çoğu dokunmatik ekranlar 6, 7, A1, A2 pinlerini kullanır."));
    Serial.println(F("Ancak bu pinler, herhangi bir sırada olabilir."));
    Serial.println(F("Örneğin, sağdan sola, yada aşağıdan yukarı"));
    Serial.println(F("ya da yanlış koordinat"));
    Serial.println(F("Kullanılan TFT ekran çeşidine göre düzenleme ve güncelleme yapınız\n"));
    Serial.println(name);
    Serial.print(F("ID=0x"));
    Serial.println(ID, HEX);
    Serial.println("Ekran " + String(tft.width()) + "x" + String(tft.height()));
    Serial.println("Kalibrasyon: ");
    Serial.println("SOL = " + String(TS_LEFT) + " SAĞ  = " + String(TS_RT));
    Serial.println("YUKARI  = " + String(TS_TOP)  + " AŞAĞI = " + String(TS_BOT));
    Serial.println("Kablolama, daima PORTRAIT");
    Serial.println("YP=" + String(YP)  + " XM=" + String(XM));
    Serial.println("YM=" + String(YM)  + " XP=" + String(XP));
}

void show_tft(void)
{
    tft.setCursor(0, 0);
    tft.setTextSize(1);
    tft.print(F("ID=0x"));
    tft.println(ID, HEX);
    tft.println("Ekran " + String(tft.width()) + "x" + String(tft.height()));
    tft.println("");
    tft.setTextSize(2);
    tft.println(name);
    tft.setTextSize(1);
    tft.println("PORTRAIT Degerleri:");
    tft.println("SOL = " + String(TS_LEFT) + " SAG  = " + String(TS_RT));
    tft.println("YUKARI  = " + String(TS_TOP)  + " ASAGI = " + String(TS_BOT));
    tft.println("\nKablolama: ");
    tft.println("YP=" + String(YP)  + " XM=" + String(XM));
    tft.println("YM=" + String(YM)  + " XP=" + String(XP));
    tft.setTextSize(2);
    tft.setTextColor(RED);
    tft.setCursor((tft.width() - 48) / 2, (tft.height() * 2) / 4);
    tft.print("CIKIS");
    tft.setTextColor(YELLOW, BLACK);
    tft.setCursor(0, (tft.height() * 6) / 8);
    tft.print("loc icin dokunmatik ekran");
    while (1) {
        tp = ts.getPoint();
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        if (tp.z < MINPRESSURE || tp.z > MAXPRESSURE) continue;
        if (tp.x > 450 && tp.x < 570  && tp.y > 450 && tp.y < 570) break;
        tft.setCursor(0, (tft.height() * 3) / 4);
        tft.print("tp.x=" + String(tp.x) + " tp.y=" + String(tp.y) + "   ");
    }
}


void setup(void)
{
    uint16_t tmp;

    tft.reset();
    ID = tft.readID();
    tft.begin(ID);
    Serial.begin(9600);
    show_Serial();
    tft.setRotation(Orientation);
    tft.fillScreen(BLACK);
    show_tft();

    BOXSIZE = tft.width() / 6;
    tft.fillScreen(BLACK);

    tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
    tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, YELLOW);
    tft.fillRect(BOXSIZE * 2, 0, BOXSIZE, BOXSIZE, GREEN);
    tft.fillRect(BOXSIZE * 3, 0, BOXSIZE, BOXSIZE, CYAN);
    tft.fillRect(BOXSIZE * 4, 0, BOXSIZE, BOXSIZE, BLUE);
    tft.fillRect(BOXSIZE * 5, 0, BOXSIZE, BOXSIZE, MAGENTA);

    tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
    currentcolor = RED;
    delay(1000);
}

void loop()
{
    uint16_t xpos, ypos;  //dokunmatik ekran koordinatları. 
    tp = ts.getPoint();   
    
    pinMode(XP, OUTPUT);
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    pinMode(YM, OUTPUT);
  

    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
     
        switch (Orientation) {
            case 0:
                xpos = map(tp.x, TS_LEFT, TS_RT, 0, tft.width());
                ypos = map(tp.y, TS_TOP, TS_BOT, 0, tft.height());
                break;
            case 1:
                xpos = map(tp.y, TS_TOP, TS_BOT, 0, tft.width());
                ypos = map(tp.x, TS_RT, TS_LEFT, 0, tft.height());
                break;
            case 2:
                xpos = map(tp.x, TS_RT, TS_LEFT, 0, tft.width());
                ypos = map(tp.y, TS_BOT, TS_TOP, 0, tft.height());
                break;
            case 3:
                xpos = map(tp.y, TS_BOT, TS_TOP, 0, tft.width());
                ypos = map(tp.x, TS_LEFT, TS_RT, 0, tft.height());
                break;
        }

       
        if (ypos < BOXSIZE) {               //renk kutucukların etrafına beyaz çizgi çeker.
            oldcolor = currentcolor;

            if (xpos < BOXSIZE) {
                currentcolor = RED;
                tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
            } else if (xpos < BOXSIZE * 2) {
                currentcolor = YELLOW;
                tft.drawRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, WHITE);
            } else if (xpos < BOXSIZE * 3) {
                currentcolor = GREEN;
                tft.drawRect(BOXSIZE * 2, 0, BOXSIZE, BOXSIZE, WHITE);
            } else if (xpos < BOXSIZE * 4) {
                currentcolor = CYAN;
                tft.drawRect(BOXSIZE * 3, 0, BOXSIZE, BOXSIZE, WHITE);
            } else if (xpos < BOXSIZE * 5) {
                currentcolor = BLUE;
                tft.drawRect(BOXSIZE * 4, 0, BOXSIZE, BOXSIZE, WHITE);
            } else if (xpos < BOXSIZE * 6) {
                currentcolor = MAGENTA;
                tft.drawRect(BOXSIZE * 5, 0, BOXSIZE, BOXSIZE, WHITE);
            }

            if (oldcolor != currentcolor) { 
                if (oldcolor == RED) tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
                if (oldcolor == YELLOW) tft.fillRect(BOXSIZE, 0, BOXSIZE, BOXSIZE, YELLOW);
                if (oldcolor == GREEN) tft.fillRect(BOXSIZE * 2, 0, BOXSIZE, BOXSIZE, GREEN);
                if (oldcolor == CYAN) tft.fillRect(BOXSIZE * 3, 0, BOXSIZE, BOXSIZE, CYAN);
                if (oldcolor == BLUE) tft.fillRect(BOXSIZE * 4, 0, BOXSIZE, BOXSIZE, BLUE);
                if (oldcolor == MAGENTA) tft.fillRect(BOXSIZE * 5, 0, BOXSIZE, BOXSIZE, MAGENTA);
            }
        }
       
        if (((ypos - PENRADIUS) > BOXSIZE) && ((ypos + PENRADIUS) < tft.height())) {
            tft.fillCircle(xpos, ypos, PENRADIUS, currentcolor);
        }
     
        if (ypos > tft.height() - 10) {
           
            tft.fillRect(0, BOXSIZE, tft.width(), tft.height() - BOXSIZE, BLACK);
        }
    }
}
