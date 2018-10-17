/* Reads RFID cards using a RC522 card reader and compare serial ids to known one.
 *
 * Uses library MFRC522 (https://github.com/miguelbalboa/rfid)
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define RED_PIN 2
#define YELLOW_PIN 3
#define GREEN_PIN 4

MFRC522 rfid(SS_PIN, RST_PIN);

byte nuidPICC[4];
byte whitePICC[] = { 0xC0, 0xE4, 0xCD, 0xA3 };
byte bluePICC[] = { 0XA6, 0xDF, 0x65, 0xD9 };

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  // Store NUID into nuidPICC array
  for (byte i = 0; i < 4; i++) {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  if (comparePICC(rfid.uid.uidByte, whitePICC)) {
    Serial.println("White PICC detected");
    digitalWrite(GREEN_PIN, HIGH);
    delay(200);
    digitalWrite(GREEN_PIN, LOW);
    delay(200);
    digitalWrite(GREEN_PIN, HIGH);
    delay(200);
    digitalWrite(GREEN_PIN, LOW);
  } else if (comparePICC(rfid.uid.uidByte, bluePICC)) {
    Serial.println("Blue PICC detected");
    digitalWrite(RED_PIN, HIGH);
    delay(200);
    digitalWrite(RED_PIN, LOW);
    delay(200);
    digitalWrite(RED_PIN, HIGH);
    delay(200);
    digitalWrite(RED_PIN, LOW);
  } else {
    Serial.println("Unknown PICC");
    digitalWrite(YELLOW_PIN, HIGH);
    delay(200);
    digitalWrite(YELLOW_PIN, LOW);
    delay(200);
    digitalWrite(YELLOW_PIN, HIGH);
    delay(200);
    digitalWrite(YELLOW_PIN, LOW);
  }

  rfid.PICC_HaltA();

  rfid.PCD_StopCrypto1();
}


int comparePICC(byte *left, byte *right) {
  for (byte i = 0; i < 4; i++) {
    if (left[i] != right[i]) {
      return false;
    }
  }
  return true;
}
