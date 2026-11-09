// --- PIN TANIMLARI ---
const int DIN_PIN = 12; // MAX7219 DIN
const int CS_PIN  = 11; // MAX7219 CS (LOAD)
const int CLK_PIN = 10; // MAX7219 CLK

const int MODUL_SAYISI = 4; // 4 adet 8x8 modül = 32 sütun
byte displayBuffer[32];     // 32 sütunluk ekran bellek tamponu

// --- MAX7219 REGISTERLARI ---
#define REG_NOOP         0x00
#define REG_DECODE_MODE  0x09
#define REG_INTENSITY    0x0A
#define REG_SCAN_LIMIT   0x0B
#define REG_SHUTDOWN     0x0C
#define REG_DISPLAY_TEST 0x0F

// --- STANDART 5x8 FONT TABLOSU ---
const byte FONT[][5] = {
  {0x7E, 0x11, 0x11, 0x11, 0x7E}, // A (0)
  {0x7F, 0x49, 0x49, 0x49, 0x36}, // B (1)
  {0x3E, 0x41, 0x41, 0x41, 0x22}, // C (2)
  {0x7F, 0x41, 0x41, 0x22, 0x1C}, // D (3)
  {0x7F, 0x49, 0x49, 0x49, 0x41}, // E (4)
  {0x7F, 0x09, 0x09, 0x09, 0x01}, // F (5)
  {0x3E, 0x41, 0x49, 0x49, 0x7A}, // G (6)
  {0x7F, 0x08, 0x08, 0x08, 0x7F}, // H (7)
  {0x00, 0x41, 0x7F, 0x41, 0x00}, // I (8)
  {0x20, 0x40, 0x41, 0x3F, 0x01}, // J (9)
  {0x7F, 0x08, 0x14, 0x22, 0x41}, // K (10)
  {0x7F, 0x40, 0x40, 0x40, 0x40}, // L (11)
  {0x7F, 0x02, 0x0C, 0x02, 0x7F}, // M (12)
  {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N (13)
  {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O (14)
  {0x7F, 0x09, 0x09, 0x09, 0x06}, // P (15)
  {0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q (16)
  {0x7F, 0x09, 0x19, 0x29, 0x46}, // R (17)
  {0x46, 0x49, 0x49, 0x49, 0x31}, // S (18)
  {0x01, 0x01, 0x7F, 0x01, 0x01}, // T (19)
  {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U (20)
  {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V (21)
  {0x7F, 0x20, 0x18, 0x20, 0x7F}, // W (22)
  {0x63, 0x14, 0x08, 0x14, 0x63}, // X (23)
  {0x07, 0x08, 0x70, 0x08, 0x07}, // Y (24)
  {0x61, 0x51, 0x49, 0x45, 0x43}, // Z (25)
  {0x00, 0x00, 0x00, 0x00, 0x00}  // Bosluk (26)
};

// 4 modülün tamamına aynı ayar komutunu yollar
void sendCommandAll(byte reg, byte data) {
  digitalWrite(CS_PIN, LOW);
  for (int i = 0; i < MODUL_SAYISI; i++) {
    shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, reg);
    shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, data);
  }
  digitalWrite(CS_PIN, HIGH);
}

// 32 sütunluk tamponu 4 modüle aktarır
void refreshPanels() {
  for (byte row = 1; row <= 8; row++) {
    digitalWrite(CS_PIN, LOW);
    // Zincirin sonundaki 4. modülden ilk modüle doğru gönderilir
    for (int mod = MODUL_SAYISI - 1; mod >= 0; mod--) {
      byte colIndex = (mod * 8) + (row - 1);
      shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, row);
      shiftOut(DIN_PIN, CLK_PIN, MSBFIRST, displayBuffer[colIndex]);
    }
    digitalWrite(CS_PIN, HIGH);
  }
}

// Ekranı sola 1 sütun kaydırıp en sağa yeni sütun verisi ekler
void scrollLeft(byte newColumn) {
  for (int i = 0; i < 31; i++) {
    displayBuffer[i] = displayBuffer[i + 1];
  }
  displayBuffer[31] = newColumn;
  refreshPanels();
}

// Bir harfi sütun sütun ekrana akıtır
void printChar(char c, int scrollDelay) {
  int fontIndex = 26; // Varsayılan boşluk
  
  if (c >= 'A' && c <= 'Z') {
    fontIndex = c - 'A';
  } else if (c >= 'a' && c <= 'z') {
    fontIndex = c - 'a'; // Küçük harfleri büyüt
  }

  // Harfin 5 sütununu sırayla kaydır
  for (int col = 0; col < 5; col++) {
    scrollLeft(FONT[fontIndex][col]);
    delay(scrollDelay);
  }
  // Harfler arasında 1 sütunluk boşluk bırak
  scrollLeft(0x00);
  delay(scrollDelay);
}

// Cümleyi/İsmi kaydırır
void scrollText(const char* text, int scrollDelay) {
  while (*text) {
    printChar(*text, scrollDelay);
    text++;
  }
}

void setup() {
  pinMode(DIN_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);

  // 4 modülün donanımını başlat
  sendCommandAll(REG_DISPLAY_TEST, 0x00);
  sendCommandAll(REG_DECODE_MODE, 0x00);
  sendCommandAll(REG_SCAN_LIMIT, 0x07);
  sendCommandAll(REG_INTENSITY, 0x05); // Parlaklık
  sendCommandAll(REG_SHUTDOWN, 0x01);  // Aç

  // Ekran belleğini temizle
  for (int i = 0; i < 32; i++) {
    displayBuffer[i] = 0x00;
  }
  refreshPanels();
}

void loop() {
  // Kaydırmak istediğiniz metin (Büyük/küçük harf destekler):
  scrollText("MEHMET AKIF OCAK   ", 60); // 60ms kayma hızı
}
