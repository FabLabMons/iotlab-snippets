/* Reads temperature and humidity from a DHT11 sensor on pin 2 and displays them on the console.
 *
 * Uses the SimpleDHT library (https://github.com/winlinvip/SimpleDHT).
 */

#include <SimpleDHT.h>

const int pinDHT11 = 2;

SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(115200);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    /* An error was detected. */
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
  } else {
    Serial.print("Sample OK: ");
    Serial.print((int)temperature);
    Serial.print(" °C, ");
    Serial.print((int)humidity);
    Serial.println(" %H");
  }
  /* DHT11 sensor cannot sense more than once per second. */
  delay(1500);
}
