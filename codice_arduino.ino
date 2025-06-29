#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_NeoPixel.h>

#define SS_PIN_1 10  // Lettore 1 (luogo)
#define SS_PIN_2 11   // Lettore 2 (oggetto)
#define SS_PIN_3 8  // Lettore 3 (oggetto)
#define RST_PIN 9

#define PIN_NEOPIXEL 6
#define NUMPIXELS 48

MFRC522 rfid1(SS_PIN_1, RST_PIN);  // Luogo
MFRC522 rfid2(SS_PIN_2, RST_PIN);  // Oggetto 1
MFRC522 rfid3(SS_PIN_3, RST_PIN);  // Oggetto 2

Adafruit_NeoPixel ring(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

// === ID Luoghi ===
byte farmacia[7]   = {0x04, 0x97, 0x24, 0x6A, 0xBF, 0x2A, 0x81};
byte spiaggia[7]   = {0x04, 0x9F, 0x36, 0x6A, 0xBF, 0x2A, 0x81};
byte porto[7]      = {0x04, 0xC4, 0x54, 0x6A, 0xBF, 0x2A, 0x81};
byte scuola[7]     = {0x04, 0x4C, 0x19, 0x6A, 0xBF, 0x2A, 0x81};
byte cucina[7]     = {0x04, 0x47, 0x13, 0x6A, 0xBF, 0x2A, 0x81};
byte parco[7]      = {0x04, 0xF5, 0x41, 0x6A, 0xBF, 0x2A, 0x81};
byte camera[7]     = {0x04, 0xCA, 0x2F, 0x6A, 0xBF, 0x2A, 0x81};
byte pranzo[7]     = {0x04, 0x9D, 0x47, 0x6A, 0xBF, 0x2A, 0x81};

// === Oggetti ===
byte asciugamano[7]     = {0x04, 0xCE, 0x6A, 0x69, 0xBF, 0x2A, 0x81};
byte ombrellone[7]      = {0x04, 0x67, 0xA3, 0x69, 0xBF, 0x2A, 0x81};
byte paletta[7]         = {0x04, 0x6C, 0x71, 0x69, 0xBF, 0x2A, 0x81};
byte palla[7]           = {0x04, 0xCD, 0xE2, 0x69, 0xBF, 0x2A, 0x81};
byte pesci[7]           = {0x04, 0xF1, 0x86, 0x69, 0xBF, 0x2A, 0x81};
byte ancora[7]    = {0x04, 0xF5, 0x7B, 0x6A, 0xBF, 0x2A, 0x81};
byte barca[7]           = {0x04, 0xA6, 0x76, 0x6A, 0xBF, 0x2A, 0x81};
byte valigia[7]         = {0x04, 0x42, 0xB6, 0x69, 0xBF, 0x2A, 0x81};
byte rete[7]            = {0x04, 0xBC, 0xCA, 0x69, 0xBF, 0x2A, 0x81};
byte panchina[7]        = {0x04, 0x86, 0x95, 0x69, 0xBF, 0x2A, 0x81};
byte fiori[7]           = {0x04, 0x33, 0x92, 0x69, 0xBF, 0x2A, 0x81};
byte alberi[7]          = {0x04, 0xE6, 0xE8, 0x69, 0xBF, 0x2A, 0x81};
byte altalena[7]        = {0x04, 0xB8, 0x96, 0x69, 0xBF, 0x2A, 0x81};
byte alfabeto[7]        = {0x04, 0x4E, 0x46, 0x69, 0xBF, 0x2A, 0x81};
byte zaino[7]           = {0x04, 0xC1, 0x3D, 0x69, 0xBF, 0x2A, 0x81};
byte lavagna[7]         = {0x04, 0xD8, 0x3D, 0x69, 0xBF, 0x2A, 0x81};
byte libri[7]           = {0x04, 0x6A, 0x42, 0x69, 0xBF, 0x2A, 0x81};
byte piatti[7]          = {0x04, 0xD8, 0x56, 0x69, 0xBF, 0x2A, 0x81};
byte cibo[7]            = {0x04, 0x27, 0x5C, 0x69, 0xBF, 0x2A, 0x81};
byte centrotavola[7]    = {0x04, 0x90, 0x47, 0x6A, 0xBF, 0x2A, 0x81};
byte pentola[7]         = {0x04, 0x76, 0x81, 0x6A, 0xBF, 0x2A, 0x81};
byte tazza[7]           = {0x04, 0x9D, 0x89, 0x6A, 0xBF, 0x2A, 0x81};
byte bicchiere[7]       = {0x04, 0xBB, 0x4A, 0x69, 0xBF, 0x2A, 0x81};
byte mestolo[7]         = {0x04, 0xD1, 0xFA, 0x69, 0xBF, 0x2A, 0x81};
byte croce[7]           = {0x04, 0xAC, 0xC4, 0x69, 0xBF, 0x2A, 0x81};
byte medicine[7]        = {0x04, 0xA6, 0xA4, 0x69, 0xBF, 0x2A, 0x81};
byte termometro[7]      = {0x04, 0xEB, 0x97, 0x69, 0xBF, 0x2A, 0x81};
byte cerotto[7]         = {0x04, 0x91, 0xAA, 0x69, 0xBF, 0x2A, 0x81};
byte creme[7]      = {0x04, 0xBE, 0xF4, 0x69, 0xBF, 0x2A, 0x81};
byte tappeto[7]         = {0x04, 0xE8, 0x71, 0x6A, 0xBF, 0x2A, 0x81};
byte comodino[7]        = {0x04, 0x66, 0x81, 0x69, 0xBF, 0x2A, 0x81};
byte pantofole[7]       = {0x04, 0x67, 0x68, 0x6A, 0xBF, 0x2A, 0x81};
byte letto[7]           = {0x04, 0x7E, 0x5E, 0x6A, 0xBF, 0x2A, 0x81};
byte cuscino[7]          = {0x04, 0xA8, 0x80, 0x6A, 0xBF, 0x2A, 0x81};

byte luogoAttivo[7] = {0};
bool luogoMemorizzato = false;
int erroriLuogo = 0;
bool oggetto1Corretto = false;
bool oggetto2Corretto = false;

// === DICHIARAZIONE FUNZIONI ===
bool compareUID(byte *a, byte *b);
bool checkAssociazione(byte *luogo, byte *oggetto);
void accendiRing(int start, int end, uint32_t colore);
void spegniRing();
void effettoCambioLuogo();

// === SETUP ===
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid1.PCD_Init();
  rfid2.PCD_Init();
  rfid3.PCD_Init();

  pinMode(SS_PIN_1, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  pinMode(SS_PIN_3, OUTPUT);
  digitalWrite(SS_PIN_1, HIGH);
  digitalWrite(SS_PIN_2, HIGH);
  digitalWrite(SS_PIN_3, HIGH);

  ring.begin();
  ring.show();

  effettoAccensioneSpecchio();

  Serial.println("Sistema RFID pronto.");
}

// === LOOP ===
void loop() {
  checkLettore(rfid1, SS_PIN_1, true, 0);
  checkLettore(rfid2, SS_PIN_2, false, 36);
  checkLettore(rfid3, SS_PIN_3, false, 0);
}

// === CHECK LETTORE ===
void checkLettore(MFRC522 &lettore, int pinSS, bool isLuogo, int ledOffset) {
  digitalWrite(pinSS, LOW);
  if (lettore.PICC_IsNewCardPresent() && lettore.PICC_ReadCardSerial()) {
    byte* uid = lettore.uid.uidByte;
    if (isLuogo) {
      if (!compareUID(luogoAttivo, uid)) {
        memcpy(luogoAttivo, uid, 7);
        luogoMemorizzato = true;
        erroriLuogo = 0;
        Serial.println("Cambio di luogo rilevato.");
        effettoCambioLuogo();
        accendiRing(12, 36, ring.Color(255, 255, 255));
        delay(1000);
        spegniRing();
      }
    } else {
      if (!luogoMemorizzato) {
        Serial.println("Nessun luogo memorizzato.");
        accendiRing(12, 36, ring.Color(255, 0, 0));
        delay(500);
        spegniRing();
      } else {
        if (checkAssociazione(luogoAttivo, uid)) {
          Serial.println("Oggetto CORRETTO");
          accendiRing(ledOffset, ledOffset + 12, ring.Color(0, 255, 0));
          if (ledOffset == 0) oggetto1Corretto = true;
          else if (ledOffset == 36) oggetto2Corretto = true;
        } else {
          Serial.println("Oggetto SBAGLIATO");
          erroriLuogo++;
          if (erroriLuogo >= 3) {
            Serial.println("TROPPI ERRORI – LUOGO BLOCCATO");
            accendiRing(0, 48, ring.Color(255, 0, 0));
            delay(1500);
            spegniRing();
          } else {
            accendiRing(ledOffset, ledOffset + 12, ring.Color(255, 0, 0));
            delay(1000);
            spegniRing();
          }
        }
      }
    }
    lettore.PICC_HaltA();
    lettore.PCD_StopCrypto1();
    delay(500);
  }
  digitalWrite(pinSS, HIGH);

  if (oggetto1Corretto && oggetto2Corretto) {
    Serial.println("Tutte le associazioni sono corrette!");
    accendiRing(0, 48, ring.Color(0, 255, 0));
    delay(1000);
    spegniRing();
    oggetto1Corretto = false;
    oggetto2Corretto = false;
  }
}

// === FUNZIONI ===

void effettoAccensioneSpecchio() {
  int start = 0;
  int end = NUMPIXELS - 1;
  while (start <= end) {
    ring.setPixelColor(start, ring.Color(255, 255, 255));
    if (end != start) ring.setPixelColor(end, ring.Color(255, 255, 255));
    ring.show();
    delay(50);
    start++;
    end--;
  }
  delay(300);
  spegniRing();
}

bool compareUID(byte *a, byte *b) {
  for (byte i = 0; i < 7; i++) if (a[i] != b[i]) return false;
  return true;
}

bool checkAssociazione(byte *luogo, byte *oggetto) {
  if (compareUID(luogo, farmacia))
    return compareUID(oggetto, croce) || compareUID(oggetto, medicine) || compareUID(oggetto, cerotto) || compareUID(oggetto, creme) || compareUID(oggetto, termometro);
  if (compareUID(luogo, spiaggia))
    return compareUID(oggetto, asciugamano) || compareUID(oggetto, ombrellone) || compareUID(oggetto, paletta) || compareUID(oggetto, palla) || compareUID(oggetto, barca) || compareUID(oggetto, pesci);
  if (compareUID(luogo, porto))
    return compareUID(oggetto, pesci) || compareUID(oggetto, ancora) || compareUID(oggetto, valigia) || compareUID(oggetto, rete) || compareUID(oggetto, barca);
  if (compareUID(luogo, scuola))
    return compareUID(oggetto, altalena) || compareUID(oggetto, alfabeto) || compareUID(oggetto, zaino) || compareUID(oggetto, lavagna) || compareUID(oggetto, libri);
  if (compareUID(luogo, cucina))
    return compareUID(oggetto, pentola) || compareUID(oggetto, piatti) || compareUID(oggetto, cibo) || compareUID(oggetto, tazza) || compareUID(oggetto, bicchiere) || compareUID(oggetto, mestolo);
  if (compareUID(luogo, parco))
    return compareUID(oggetto, altalena) || compareUID(oggetto, panchina) || compareUID(oggetto, fiori) || compareUID(oggetto, alberi) || compareUID(oggetto, palla);
  if (compareUID(luogo, camera))
    return compareUID(oggetto, tappeto) || compareUID(oggetto, comodino) || compareUID(oggetto, pantofole) || compareUID(oggetto, letto) || compareUID(oggetto, libri) || compareUID(oggetto, cuscino);
  if (compareUID(luogo, pranzo))
    return compareUID(oggetto, piatti) || compareUID(oggetto, cibo) || compareUID(oggetto, centrotavola) || compareUID(oggetto, bicchiere);
  return false;
}

void accendiRing(int start, int end, uint32_t colore) {
  uint8_t r = (uint8_t)(colore >> 16);
  uint8_t g = (uint8_t)(colore >> 8);
  uint8_t b = (uint8_t)(colore);
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    for (int i = start; i < end; i++) {
      ring.setPixelColor(i, ring.Color((r * brightness) / 255, (g * brightness) / 255, (b * brightness) / 255));
    }
    ring.show();
    delay(20);
  }
}

void spegniRing() {
  ring.clear();
  ring.show();
}

void effettoCambioLuogo() {
  for (int i = 12; i < 36; i++) {
    ring.setPixelColor(i, ring.Color(255, 255, 255));
    ring.show();
    delay(50);
  }
  delay(200);
  spegniRing();
}
