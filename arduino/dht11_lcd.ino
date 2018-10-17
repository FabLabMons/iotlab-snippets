/* Reads temperature and humidity from a DHT11 sensor on pin 2 and displays them
 *
 * Uses the libraries:
 * * SimpleDHT (https://github.com/winlinvip/SimpleDHT)
 * * LiquidCrystal I2C (https://github.com/marcoschwartz/LiquidCrystal_I2C)
 */

#include <SimpleDHT.h>
#include <LiquidCrystal_I2C.h>

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  char buffer[16];
  lcd.print("Temp: ");
  lcd.print(String(temperature));
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(String(humidity));
  lcd.print(" %");

  delay(1500);
}
